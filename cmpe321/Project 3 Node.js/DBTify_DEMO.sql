DROP DATABASE dbtify;

CREATE DATABASE IF NOT EXISTS dbtify;
USE dbtify;
CREATE TABLE IF NOT EXISTS listeners(
	username VARCHAR(64),
    email VARCHAR(64),
    PRIMARY KEY(username)
);
CREATE TABLE IF NOT EXISTS artists(
	name VARCHAR(64),
    surname VARCHAR(63),
    username  VARCHAR(128),
    likes_artist INT,
    PRIMARY KEY(username)
);
CREATE TABLE IF NOT EXISTS albums(
	id_album INT UNIQUE,
    artist VARCHAR(128),
    genre VARCHAR(64),
    title_album VARCHAR(64),
    likes_album INT,
    PRIMARY KEY(id_album),
    FOREIGN KEY (artist) REFERENCES artists(username)
);
CREATE TABLE IF NOT EXISTS songs(
	id_song INT UNIQUE,
    id_album INT,
	title_song VARCHAR(64),
    likes_song INT,
    PRIMARY KEY(id_song),
    FOREIGN KEY (id_album) REFERENCES albums(id_album)
);
CREATE TABLE IF NOT EXISTS listener_likes_song(
	listener VARCHAR(64),
    id_song INT,
    FOREIGN KEY (listener) REFERENCES listeners(username),
    FOREIGN KEY (id_song) REFERENCES songs(id_song)
);
CREATE TABLE IF NOT EXISTS listener_likes_album(
	listener VARCHAR(64),
    id_album INT,
    FOREIGN KEY (listener) REFERENCES listeners(username),
    FOREIGN KEY (id_album) REFERENCES albums(id_album)
);
CREATE TABLE IF NOT EXISTS song_artist(
    id_song INT,
	artist VARCHAR(128),
    FOREIGN KEY (id_song) REFERENCES songs(id_song),
    FOREIGN KEY (artist) REFERENCES artists(username)
);
CREATE TABLE IF NOT EXISTS album_artist(
    id_album INT,
	artist VARCHAR(128),
    FOREIGN KEY (id_album) REFERENCES albums(id_album),
    FOREIGN KEY (artist) REFERENCES artists(username)
);

INSERT INTO listeners (username, email) VALUES
	("selenparlar" , "parlarselen@gmail.com"),
	("taflangundem" , "gundem@boun.edu.tr"),
	("can" , "can@gmail.com"),
	("pelin" , "pelin@gmail.com"),
	("daniel_ek" , "daniel@spotify.com");

INSERT INTO artists (name, surname, username, likes_artist) VALUES
	("Ceylan", "Ertem", "Ceylan_Ertem", 3),
	("Fikret", "Kizilok", "Fikret_Kizilok", 1),
	("Kansas", "", "Kansas_", 4),
	("Manga", "", "Manga_", 1),
	("MFO", "", "MFO_", 0),
	("Neset", "Ertas", "Neset_Ertas", 1),
	("Pinhani", "", "Pinhani_", 2),
	("Queen", "", "Queen_", 4),
	("R.E.M", "", "R.E.M_", 5),
	("Sezen", "Aksu", "Sezen_Aksu", 4),
	("Tuna", "Kiremitci", "Tuna_Kiremitci", 2),
	("Coskun", "Karademir", "Coskun_Karademir", 1),
	("Mert Fehmi", "Alatan", "Mert Fehmi_Alatan", 1),
	("Berkant", "Celen", "Berkant_Celen", 1),
	("Alp", "Ersonmez", "Alp_Ersonmez", 2),
	("Can", "Gungor", "Can_Gungor", 3),
	("Cihan", "Murtazaoglu", "Cihan_Murtazaoglu", 1),
	("Elis", "Dubaz", "Elis_Dubaz", 1),
	("Esin", "Iris", "Esin_Iris", 1);

INSERT INTO albums (id_album, artist, genre, title_album, likes_album) VALUES
	(14, "Ceylan_Ertem", "Pop", "Soluk", 2),
	(15, "Ceylan_Ertem", "Pop", "Cahille Sohbeti Kestim", 1),
	(16, "Fikret_Kizilok", "Pop", "Yadigar", 0),
	(9, "Kansas_", "Rock", "Point of Know Return", 4),
	(18, "Manga_", "Alternative", "Sehri Huzun", 0),
	(19, "MFO_", "Rock", "Geldiler", 0),
	(17, "Neset_Ertas", "Abdallik", "Gonul Dagi", 0),
	(2, "Pinhani_", "Rock", "Yollar Bizi Bekler", 0),
	(10, "Queen_", "Rock", "The Game", 0),
	(11, "Queen_", "Rock", "News Of The World", 0),
	(13, "R.E.M_", "Rock", "Out Of Time", 5),
	(1, "Sezen_Aksu", "Pop", "Allahaismarladik", 3),
	(7, "Sezen_Aksu", "Pop", "DEMO", 1),
	(4, "Sezen_Aksu", "Pop", "Tuna Kiremitci ve Arkadasları, Vol. 2", 1);

INSERT INTO songs (id_song, id_album, title_song, likes_song) VALUES
	(140 , "14", "Gonul Dagi", 1),
	(141 , "14", "Nazima", 1),
	(150 , "15", "Farketmeden", 1),
	(160 , "16", "Farketmeden", 1),
	(90 , "9", "Dust In The Wind", 4),
	(180 , "18", "Dunyanin Sonuna Dogmusum", 1),
	(190 , "19", "Ali Desidero", 0),
	(170 , "17", "Gonul Dagi", 1),
	(20 , "2", "Gor Beni", 2),
	(100 , "10", "Another One Bites The Dust", 2),
	(110 , "11", "We Will Rock You", 2),
	(130 , "13", "Losing My Religion", 5),
	(10 , "1", "Kusura Bakma", 3),
	(70 , "7", "Begonvil", 1),
	(40 , "4", "Balkan Kizi", 1),
	(41 , "4", "Seninle Her Sey Olur", 1);

INSERT INTO song_artist (id_song, artist) VALUES
	(140, "Ceylan_Ertem"),
	(140, "Coskun_Karademir"),
	(140, "Mert Fehmi_Alatan"),
	(140, "Berkant_Celen"),
	(140, "Alp_Ersonmez"),
	(140, "Can_Gungor"),
	(141, "Ceylan_Ertem"),
	(141, "Cihan_Murtazaoglu"),
	(141, "Alp_Ersonmez"),
	(141, "Can_Gungor"),
	(150, "Ceylan_Ertem"),
	(150, "Can_Gungor"),
	(160, "Fikret_Kizilok"),
	(90, "Kansas_"),
	(180, "Manga_"),
	(190, "MFO_"),
	(170, "Neset_Ertas"),
	(20, "Pinhani_"),
	(100, "Queen_"),
	(110, "Queen_"),
	(130, "R.E.M_"),
	(10, "Sezen_Aksu"),
	(70, "Sezen_Aksu"),
	(40, "Tuna_Kiremitci"),
	(40, "Elis_Dubaz"),
	(41, "Tuna_Kiremitci"),
	(41, "Esin_Iris");
    
INSERT INTO album_artist (id_album, artist) VALUES
	(14, "Ceylan_Ertem"),
	(14, "Coskun_Karademir"),
	(14, "Mert Fehmi_Alatan"),
	(14, "Berkant_Celen"),
	(14, "Alp_Ersonmez"),
	(14, "Can_Gungor"),
	(14, "Cihan_Murtazaoglu"),
	(15, "Ceylan_Ertem"),
	(15, "Can_Gungor"),
	(16, "Fikret_Kizilok"),
	(9, "Kansas_"),
	(18, "Manga_"),
	(19, "MFO_"),
	(17, "Neset_Ertas"),
	(2, "Pinhani_"),
	(10, "Queen_"),
	(11, "Queen_"),
	(13, "R.E.M_"),
	(1, "Sezen_Aksu"),
	(7, "Sezen_Aksu"),
	(4, "Tuna_Kiremitci"),
	(4, "Elis_Dubaz"),
	(4, "Esin_Iris");

INSERT INTO listener_likes_song (listener, id_song) VALUES
	("selenparlar", 40),
	("selenparlar", 10),
	("selenparlar", 130),
	("selenparlar", 20),
	("selenparlar", 41),
	("selenparlar", 90),
	("taflangundem", 90),
	("taflangundem", 110),
	("taflangundem", 100),
	("taflangundem", 130),
	("taflangundem", 10),
	("can", 130),
	("can", 140),
	("can", 141),
	("can", 150),
	("can", 160),
	("can", 170),
	("can", 90),
	("pelin", 180),
	("pelin", 20),
	("pelin", 10),
	("pelin", 70),
	("pelin", 130),
	("daniel_ek", 90),
	("daniel_ek", 110),
	("daniel_ek", 100),
	("daniel_ek", 130);

INSERT INTO listener_likes_album (listener, id_album) VALUES
	("selenparlar", 4),
	("selenparlar", 1),
	("selenparlar", 9),
	("selenparlar", 13),
	("selenparlar", 14),
	("taflangundem", 9),
	("taflangundem", 1),
	("taflangundem", 13),
	("can", 9),
	("can", 13),
	("can", 14),
	("can", 15),
	("pelin", 1),
	("pelin", 7),
	("pelin", 13),
	("daniel_ek", 9),
	("daniel_ek", 13);

CREATE TRIGGER delete_album_song AFTER DELETE 
	ON albums FOR EACH ROW
	DELETE FROM songs WHERE songs.id_album = OLD.id_album;
CREATE TRIGGER delete_album_like AFTER DELETE
	ON albums FOR EACH ROW
    DELETE FROM listener_likes_album WHERE listener_likes_album.id_album = OLD.id_album;

CREATE TRIGGER delete_song_artist AFTER DELETE
	ON songs FOR EACH ROW
    DELETE FROM song_artist WHERE song_artist.id_song = OLD.id_song;
CREATE TRIGGER delete_song_like AFTER DELETE
	ON songs FOR EACH ROW
    DELETE FROM listener_likes_song WHERE listelistener_likes_albumner_likes_song.id_song = OLD.id_song;
    
CREATE TRIGGER like_album_songs AFTER INSERT
	ON listener_likes_album FOR EACH ROW
    INSERT INTO listener_likes_song (listener, id_song)
		SELECT
			NEW.listener,
			id_song FROM songs WHERE songs.id_album = NEW.id_album AND NOT EXISTS(
				SELECT * FROM listener_likes_song WHERE
					listener_likes_song.listener = NEW.listener AND
                    listener_likes_song.id_song = songs.id_song
            );

CREATE TRIGGER like_song_increment_artist BEFORE INSERT
	ON listener_likes_song FOR EACH ROW
    UPDATE songs
			LEFT JOIN song_artist ON songs.id_song = song_artist.id_song
			LEFT JOIN artists ON song_artist.artist = artists.username
		SET artists.likes_artist = artists.likes_artist + 1
		WHERE songs.id_song = NEW.id_song;

CREATE PROCEDURE songTogether(username VARCHAR(128))
	SELECT DISTINCT second.artist
        FROM song_artist first INNER JOIN song_artist second ON first.id_song = second.id_song
        WHERE first.artist = username AND NOT first.artist = second.artist;