% omer cihan benzer
% 2017400048
% compiling: yes
% complete: yes

:- [artists, albums, tracks]. % should this be included?

%getArtistTracks, gets Artist Tracks
getArtistTracks2(ArtistName, TrackID, TrackName):- track(TrackID, TrackName, [ArtistName|_], _, _).
getArtistTracks(ArtistName, TrackIDs, TrackNames) :- 
    findall(Id, getArtistTracks2(ArtistName, Id, _), TrackIDs),
    findall(Name, getArtistTracks2(ArtistName, _, Name), TrackNames).

%what lies below is art, custom maplist/16
mymaplist(_Predicate, [], [], [], [], [], [], [], [], [], [], [], [], [], [], []).
mymaplist(Predicate, [H1|T1], [H2|T2], [H3|T3], [H4|T4], [H5|T5], [H6|T6], [H7|T7], [H8|T8], [H9|T9], [H10|T10], [H11|T11], [H12|T12], [H13|T13], [H14|T14], [H15|T15]) :-
    call(Predicate, H1, H2, H3, H4, H5, H6, H7, H8, H9, H10, H11, H12, H13, H14, H15),
    mymaplist(Predicate, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15).


%getFeatures returns the Features:
%Note that uses getFeatures/2 was returning average of a list of Tracks where getFeatures/16 returns Features of a single Track.

%getFeatures/16, returns the Features of a Track
getFeatures(TrackId, Explicit, Danceability, Energy, Key, Loudness, Mode, Speechiness, Acousticness, Instrumentalness, Liveness, Valence, Tempo, DurationMs, TimeSignature) :-
    track(TrackId, _, _, _, Features), Features = [Explicit, Danceability, Energy, Key, Loudness, Mode, Speechiness, Acousticness, Instrumentalness, Liveness, Valence, Tempo, DurationMs, TimeSignature].

%getFeatures/2, gets the average Features of multiple Tracks
getFeatures(TrackIds, Features) :-
            mymaplist(getFeatures, TrackIds, _, DanceabilityList, EnergyList, _, _, ModeList, SpeechinessList, AcousticnessList, InstrumentalnessList, LivenessList, ValenceList, _, _, _),
            length(TrackIds, Length), \+Length=0,
            sumlist(DanceabilityList, DanceabilitySum),
            sumlist(EnergyList, EnergySum),
            sumlist(ModeList, ModeSum),
            sumlist(SpeechinessList, SpeechinessSum),
            sumlist(AcousticnessList, AcousticnessSum),
            sumlist(InstrumentalnessList, InstrumentalnessSum),
            sumlist(LivenessList, LivenessSum),
            sumlist(ValenceList, ValenceSum),

            DanceabilityAvg is DanceabilitySum / Length,
            EnergyAvg is EnergySum / Length,
            ModeAvg is ModeSum / Length,
            SpeechinessAvg is SpeechinessSum / Length,
            AcousticnessAvg is AcousticnessSum / Length,
            InstrumentalnessAvg is InstrumentalnessSum / Length,
            LivenessAvg is LivenessSum / Length,
            ValenceAvg is ValenceSum / Length,

            Features = [DanceabilityAvg, EnergyAvg, ModeAvg, SpeechinessAvg, AcousticnessAvg, InstrumentalnessAvg, LivenessAvg, ValenceAvg].
getFeatures(TrackId, Features) :- % if Length=0 above at getFeatures/2
    (\+track(TrackId,_,_,_,_)), Features = [0,0,0,0,0,0,0,0].

%albumFeatures, uses the getFeatures/2(multiple Tracks)
albumFeatures(AlbumId, AlbumFeatures) :-
    album(AlbumId, _, _, TrackIdList),
    getFeatures(TrackIdList, AlbumFeatures).

%artistFeatures, uses the getFeatures/2(multiple Tracks)
artistFeatures(ArtistName, ArtistFeatures) :-
    getArtistTracks(ArtistName, TrackIdList, _),
    getFeatures(TrackIdList, ArtistFeatures).

%getDistance/3  get the square average of 2 Features
getDistance(
    [Danceability1, Energy1, Mode1, Speechiness1, Acousticness1, Instrumentalness1, Liveness1, Valence1],
    [Danceability2, Energy2, Mode2, Speechiness2, Acousticness2, Instrumentalness2, Liveness2, Valence2],
    Score) :-
        
    PreScore is ((Danceability1-Danceability2)^2 + (Energy1-Energy2)^2 + (Mode1-Mode2)^2 + (Speechiness1-Speechiness2)^2 + (Acousticness1-Acousticness2)^2 + (Instrumentalness1-Instrumentalness2)^2 + (Liveness1-Liveness2)^2 + (Valence1-Valence2)^2),
    sqrt(PreScore, Score).

%trackDistance/3, uses getFeatures/16(single Track) to be put into getDistance/3 
trackDistance(TrackId1, TrackId2, Score) :-
    getFeatures(TrackId1, _, Danceability1, Energy1, _, _, Mode1, Speechiness1, Acousticness1, Instrumentalness1, Liveness1, Valence1, _, _, _),
    getFeatures(TrackId2, _, Danceability2, Energy2, _, _, Mode2, Speechiness2, Acousticness2, Instrumentalness2, Liveness2, Valence2, _, _, _),

    getDistance([Danceability1, Energy1, Mode1, Speechiness1, Acousticness1, Instrumentalness1, Liveness1, Valence1],
        [Danceability2, Energy2, Mode2, Speechiness2, Acousticness2, Instrumentalness2, Liveness2, Valence2],Score).


%albumDistance/3, uses albumFeatures/2 for Features to be put into getDistance/3
albumDistance(Album1, Album2, Score) :-
    albumFeatures(Album1, [Danceability1, Energy1, Mode1, Speechiness1, Acousticness1, Instrumentalness1, Liveness1, Valence1]),
    albumFeatures(Album2, [Danceability2, Energy2, Mode2, Speechiness2, Acousticness2, Instrumentalness2, Liveness2, Valence2]),

    getDistance([Danceability1, Energy1, Mode1, Speechiness1, Acousticness1, Instrumentalness1, Liveness1, Valence1],
        [Danceability2, Energy2, Mode2, Speechiness2, Acousticness2, Instrumentalness2, Liveness2, Valence2],Score).

%artistDistance/3, uses artistFeatures/3 for Features to be put into getDistance/3
artistDistance(ArtistName1, ArtistName2, Score) :-
    artistFeatures(ArtistName1, [Danceability1, Energy1, Mode1, Speechiness1, Acousticness1, Instrumentalness1, Liveness1, Valence1]),
    artistFeatures(ArtistName2, [Danceability2, Energy2, Mode2, Speechiness2, Acousticness2, Instrumentalness2, Liveness2, Valence2]),

    getDistance([Danceability1, Energy1, Mode1, Speechiness1, Acousticness1, Instrumentalness1, Liveness1, Valence1],
        [Danceability2, Energy2, Mode2, Speechiness2, Acousticness2, Instrumentalness2, Liveness2, Valence2],Score).

%compareTo/3, takes one element and one list, just as maplist but one parameter is a single element
% will be used later
compareTo(_Predicate, _, [], []).
compareTo(Predicate, E1, [H2|T2], [H3|T3]) :-
    call(Predicate, E1, H2, H3),
    compareTo(Predicate, E1, T2, T3).

%After this is where fun begins

%shuffle, shuffles (is shuffle the right word for this?)
%will be used later
shuffle(List1, List2, List1-List2).
%unshuffle, unshuffles
unshuffle(List1-List2, List1, List2).

%takes the first 30 elements of a list
%will be used later
takeFirst30(BigList, SmallList) :- findall(Element, (nth1(I, BigList, Element), I=<30), SmallList).

%getNameOfATrack, to be used in call/3 later
getNameOfATrack(ID, Name) :- track(ID, Name,_,_,_).

%findMostSimilarTracks, returns nearest 30 neighbors, uses the functions above.
findMostSimilarTracks(TrackID, SimilarIDs, SimilarNames) :-
    findall(ID,track(ID,_,_,_,_), AllIDs),
    %reminder: compareTo is custom maplist
    compareTo(trackDistance, TrackID, AllIDs, Scores), 
    %shuffle, sort, unshuffle
    maplist(shuffle, Scores, AllIDs, Pairs),
    keysort(Pairs, SortedPairs),
    maplist(unshuffle, SortedPairs, _, [_|PrevSimilarIDs]),
    %organize the elements as needed
    takeFirst30(PrevSimilarIDs, SimilarIDs),
    maplist(getNameOfATrack, SimilarIDs, SimilarNames).

%getNameOfAnAlbum, to be used in call/4 later
getNameOfAnAlbum(ID, Name) :- album(ID,Name,_,_).

%findMostSimilarAlbums, returns nearest 30 neighbors, quite similar to findMostSimilarTracks
findMostSimilarAlbums(AlbumID, SimilarIDs, SimilarNames) :- 
    findall(ID, album(ID,_,_,_), AllIDs),
    %reminder: compareTo is custom maplist
    compareTo(albumDistance, AlbumID, AllIDs, Scores),
    %shuffle, sort, unshuffle
    maplist(shuffle, Scores, AllIDs, Pairs),
    keysort(Pairs, SortedPairs),
    maplist(unshuffle, SortedPairs, _, [_|PrevSimilarIDs]),
    %organize the elements as needed
    takeFirst30(PrevSimilarIDs, SimilarIDs),
    maplist(getNameOfAnAlbum, SimilarIDs, SimilarNames).

%findMostSimilarArtists, returns nearest 30 neighbors, quite similar to findMostSimilarTracks
findMostSimilarArtists(ArtistName, SimilarArtists) :-
    findall(Name, artist(Name,_,_), AllNames),
    %reminder: compareTo is custom maplist
    compareTo(artistDistance, ArtistName, AllNames, Scores),
    %shuffle, sort, unshuffle
    maplist(shuffle, Scores, AllNames, Pairs),
    keysort(Pairs, SortedPairs),
    maplist(unshuffle, SortedPairs, _, [_|PrevSimilarArtsts]),
    %organize the elements as needed
    takeFirst30(PrevSimilarArtsts, SimilarArtists).

%to be used below in exclude/3
isExplicit(TrackID) :-
    track(TrackID, _,_,_,[Explicit,_,_,_,_,_,_,_,_,_,_,_,_,_]),
    Explicit is 1.
%findExplicitTracks
filterExplicitTracks(Tracklist, FilteredTracks) :-
    exclude(isExplicit, Tracklist, FilteredTracks).

%Combine, takes multiple "List Lists" and adds them together
%I wont use this because it causes an infinite loop but it might come in handy later
combine([], List, List).
combine([Head|[]], Tail, [Head|Tail]).
combine([Head|Tail], List, BigList) :- combine(Tail, List, Tmp), combine([Head], Tmp, BigList).

%getGenres, returns the Genres of an Artist
getGenres(Artist, GenreList) :-
    artist(Artist, GenreList, _).
%getTrackGenre, returns the Genres of a Track's Artists
getTrackGenre(TrackID, Genres) :-
    track(TrackID, _, Artists, _,_),
    maplist(getGenres, Artists, GenreList),
    append(GenreList, PreGenres),
    sort(PreGenres, Genres).

%isSubstring, true if any of the Genres is a substring of the Genres of ID.
%This part is not used but it's better to keep it than deleting
isSubstring(_,[]) :- 1 is 0. % fails every time
isSubstring(Substring, [Head|Tail]) :-
        sub_string(Head, _, _, _, Substring);
        isInTheList(Substring, Tail).

%this is needed to be used in call/3 later
getArtistOfATrack(TrackID, TrackArtist) :- track(TrackID, _,[TrackArtist|_],_,_).

isIncluded(Genres, ID) :- 
% true if any of the Genres is a substring of the Genres of ID.
    getTrackGenre(ID, TrackGenres),
    member(Genre, Genres),
    member(TrackGenre, TrackGenres),
    sub_string(TrackGenre,_,_,_,Genre).

%The show we all were waiting for: 


%blacklist/whitelist, uses isIncluded
blacklist(DislikedGenres, AllIDs, FilteredIDs) :- %FilteredIDs exclude DislikedGenres
    findall(ID, (member(ID, AllIDs), \+isIncluded(DislikedGenres,ID)), FilteredIDs).

whitelist(LikedGenres, AllIDs, FilteredIDs) :- %FilteredIDs include LikedGenres
    findall(ID, (member(ID, AllIDs), isIncluded(LikedGenres, ID)), FilteredIDs).

%trackDistance2, Quite similar to trackDistance but the first parameter is already a Feature, we don't have to search for it unlike trackDistance/2
trackDistance2([Danceability1, Energy1, Mode1, Speechiness1, Acousticness1, Instrumentalness1, Liveness1, Valence1], TrackID2, Score) :-
    getFeatures(TrackID2, _, Danceability2, Energy2, _, _, Mode2, Speechiness2, Acousticness2, Instrumentalness2, Liveness2, Valence2, _, _, _),
    getDistance([Danceability1, Energy1, Mode1, Speechiness1, Acousticness1, Instrumentalness1, Liveness1, Valence1],
        [Danceability2, Energy2, Mode2, Speechiness2, Acousticness2, Instrumentalness2, Liveness2, Valence2],Score).


%discoverPlaylist, assuming Features input will be ~[0, 0.658, 0.927, 2, -6.925, 0, 0.0359, 0.0405, 0.861, 0.828, 0.358, 103.0, 333947, 4]
discoverPlaylist(LikedGenres, DislikedGenres, Features, FileName, Playlist) :-
    %find the Tracks we need to sort
    findall(ID,track(ID,_,_,_,_), AllIDs),
    %delete unnecesary Tracks
    blacklist(DislikedGenres, AllIDs, TmpIDs),
    whitelist(LikedGenres, TmpIDs, FilteredIDs),
    %get each score 
    compareTo(trackDistance2, Features, FilteredIDs, Scores),
    %shuffle, sort, unshuffle
    maplist(shuffle, Scores, FilteredIDs, Pairs),
    keysort(Pairs, SortedPairs),
    maplist(unshuffle, SortedPairs, _, PrevIDList),
    %and cut!
    takeFirst30(PrevIDList, Playlist),
    %get the other stuff we need
    maplist(getNameOfATrack, Playlist, NameList),
    maplist(getArtistOfATrack, Playlist, ArtistList),
    %only one Features to compare everything else
    compareTo(trackDistance2, Features, Playlist, DistanceList),


    %Dump the information into the FileName:
    open(FileName, write, Stream),
    writeln(Stream, Playlist),
    writeln(Stream, NameList),
    writeln(Stream, ArtistList),
    write(Stream, DistanceList),
    close(Stream).
