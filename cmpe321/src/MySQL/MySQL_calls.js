mysql_main = require("./MySQL_main");

// Check if username is a listener
module.exports.is_listener = (db, username) => {
    myquery = `SELECT * FROM listeners WHERE username = '${username}';`;
    return new Promise(((resolve, reject) => {
        mysql_main.query_execute(db, myquery)
            .then(function (result) {
                resolve(!!(result).length)
            });
    }))
}

// Check if username is an artist
module.exports.is_artist = (db, username) => {
    myquery = `SELECT * FROM artists WHERE username = '${username}';`;
    return new Promise(((resolve, reject) => {
        mysql_main.query_execute(db, myquery)
            .then(function (result) {
                resolve(!!(result).length)
            });
    }))
}

// Get all Songs
module.exports.get_songs = (db)  => {
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, "SELECT * FROM dbtify.songs ORDER BY likes_song DESC;")
            .then((result) => {
                resolve(result);
            })
    })
}
// Get all Albums
module.exports.get_albums = (db)  => {
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, "SELECT * FROM dbtify.albums ORDER BY likes_album DESC;")
            .then((result) => {
                resolve(result);
            })
    })
}
// Get all Artists
module.exports.get_artists = (db)  => {
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, "SELECT * FROM dbtify.artists ORDER BY likes_artist DESC;")
            .then((result) => {
                resolve(result);
            })
    })
}
// Get all listeners
module.exports.get_listeners = (db)  => {
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, "SELECT * FROM dbtify.listeners;")
            .then((result) => {
                resolve(result);
            })
    })
}

// Get the song named songName
module.exports.get_song = (db, songID) => {
    const query = `SELECT *
        FROM songs LEFT JOIN albums ON songs.id_album = albums.id_album
        WHERE songs.id_song = ${songID};`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                if (result.length) resolve(result[0]);
                else resolve({});
            })
    })
}
// Get the artists of song: id:songID
module.exports.song_get_artists = (db, songID) => {
    const query = `SELECT artists.*
        FROM artists LEFT JOIN song_artist ON artists.username = song_artist.artist
        WHERE song_artist.id_song = ${songID}
        ORDER BY likes_artist DESC;`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                resolve(result);
            })
    })
}

// Get the album id: aldumID
module.exports.get_album = (db, albumID) => {
    const query = `SELECT * FROM albums WHERE albums.id_album = ${albumID};`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                if (result.length) resolve(result[0]);
                else resolve({});
            })
    })
}
// Get the songs of album named albumName
module.exports.album_get_songs = (db, albumID) => {
    const query = `SELECT songs.*
        FROM songs LEFT JOIN albums ON songs.id_album = albums.id_album
        WHERE albums.id_album = ${albumID}
        ORDER BY likes_song DESC;`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                resolve(result);
            })
    })
}
// Get the artists of album: id:albumID
module.exports.album_get_artists = (db, albumID) => {
    const query = `SELECT artists.*
        FROM artists LEFT JOIN album_artist ON artists.username = album_artist.artist
        WHERE album_artist.id_album = ${albumID}
        ORDER BY likes_artist DESC;`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                resolve(result);
            })
    })
}

// Get the artist named artistName
module.exports.get_artist = (db, artistName) => {
    const query = `SELECT * FROM artists WHERE artists.username = "${artistName}";`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                if (result.length) resolve(result[0]);
                else resolve({});
            })
    })
}
// Get the songs of artist named artistName
module.exports.artist_get_songs = (db, artistName) => {
    const query = `SELECT songs.*
	FROM songs LEFT JOIN song_artist ON songs.id_song = song_artist.id_song
	WHERE song_artist.artist = "${artistName}"
	ORDER BY likes_song DESC;`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                resolve(result);
            })
    })
}
// Get the albums of artist named artistName
module.exports.artist_get_albums = (db, artistName) => {
    const query = `SELECT albums.*
	FROM albums LEFT JOIN album_artist ON albums.id_album = album_artist.id_album
	WHERE album_artist.artist = "${artistName}"
	ORDER BY likes_album DESC;`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                resolve(result);
            })
    })
}
// Get the Artists collaborated with the artist
module.exports.artist_get_artists = (db, artistName)=>{
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, `CALL songTogether("${artistName}");`)
            .then((result) => {
                resolve(result);
            })
    })
}

// Get liked songs of the listener:listener
module.exports.listener_get_liked_songs = (db, listener)  => {
    // Sorted by likes
    const query = `SELECT songs.*
        FROM listeners 
        INNER JOIN listener_likes_song ON listeners.username = listener_likes_song.listener
        INNER JOIN songs ON listener_likes_song.id_song = songs.id_song
        WHERE username = "${listener}"
        ORDER BY songs.likes_song DESC;`;

    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                resolve(result);
            })
    })
}
// Get liked songs of the listener:listener
module.exports.listener_get_liked_albums = (db, listener)  => {
    // Sorted by likes
    const query = `SELECT albums.*
        FROM listeners 
        INNER JOIN listener_likes_album ON listeners.username = listener_likes_album.listener
        INNER JOIN albums ON listener_likes_album.id_album = albums.id_album
        WHERE username = "${listener}"
        ORDER BY albums.likes_album DESC;`;

    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                resolve(result);
            })
    })
}
module.exports.listener_search_title = (db, keyword) => {
    const query = `
        SELECT * FROM dbtify.songs
        WHERE title_song LIKE "%${keyword}%"
        ORDER BY likes_song DESC;`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                resolve(result);
            })
    })
}
module.exports.listener_search_genre = (db, keyword) => {
    const query = `
        SELECT * FROM songs  
        LEFT JOIN albums ON songs.id_album = albums.id_album
        WHERE albums.genre LIKE "%${keyword}%"
        ORDER BY likes_song DESC;`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                resolve(result);
            })
    })
}
module.exports.listener_like_song = (db, username, song_id) => {
    console.log(username,song_id);
    const query =
        `INSERT INTO listener_likes_song (listener, id_song)
        SELECT "${username}", ${song_id}
        WHERE NOT EXISTS 
            (SELECT * FROM listener_likes_song WHERE listener = "${username}" AND id_song = ${song_id});`;
    const query2 = `UPDATE songs 
            SET likes_song = likes_song + 1
            WHERE id_song = ${song_id};`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                mysql_main.query_execute(db, query2)
                    .then((foo) => {
                        resolve(result);
                    })
            })
    })
}
module.exports.listener_like_album = (db, username, album_id) => {
    console.log(username, album_id);
    const query = `INSERT INTO listener_likes_album (listener, id_album)
    SELECT "${username}", "${album_id}"
    WHERE NOT EXISTS
        (SELECT * FROM listener_likes_album WHERE listener = "${username}" AND id_album = "${album_id}");`;
    const query2 =
        `UPDATE albums 
        SET likes_album = likes_album + 1
        WHERE id_album = ${album_id};`;
    const query3 = `UPDATE songs
                SET likes_song = likes_song + 1 
                WHERE id_album = ${album_id};`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result1) => {
                if (result1.message == "&Records: 0  Duplicates: 0  Warnings: 0"){
                    resolve(result1);
                }
                else{
                    mysql_main.query_execute(db, query2)
                        .then((result2) => {
                            mysql_main.query_execute(db, query3)
                                .then((result3) => {
                                    resolve(result1);
                                })
                        })
                }
            })
    })
}

module.exports.add_album = (db, params) =>{
    query =
        `INSERT INTO albums (id_album, artist, genre, title_album, likes_album)
            VALUE (${params.id}, "${params.username}", "${params.genre}", "${params.title}", 0);`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                resolve(result);
            })
    })
}
module.exports.update_album = (db, params) =>{
    query =
        `UPDATE albums SET
            genre = "${params.genre}",
            title_album = "${params.title}"
         WHERE id_album = ${params.id};`;
    query2 =
        `INSERT INTO album_artist (id_album, artist)
    SELECT ${params.id}, "${params.username}"
    WHERE NOT EXISTS 
        (SELECT * FROM album_artist WHERE id_album = ${params.id} AND artist = "${params.username}");`
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                mysql_main.query_execute(db, query2)
                    .then((foo) => {
                        resolve(result);
                    })
            })
    })
}
module.exports.delete_album = (db, params) =>{
    const query =
        `DELETE FROM albums
         WHERE id_album = ${params.id};`;
    const foreignChecks = ["SET FOREIGN_KEY_CHECKS=OFF;", "SET FOREIGN_KEY_CHECKS=ON;"];

    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, foreignChecks[0])
            .then((foreign1) => {
                mysql_main.query_execute(db, query)
                    .then((result) => {
                        mysql_main.query_execute(db, foreignChecks[1])
                            .then((foreign2) => {
                                resolve(result);
                            })
                    })
            })
    })
}
module.exports.add_song = (db, params) =>{
    query =
        `INSERT INTO songs (id_song, id_album, title_song, likes_song)
            VALUE (${params.id}, ${params.album}, "${params.title}", 0);`;
    query2 =
        `INSERT INTO song_artist (id_song, artist)
    SELECT ${params.id}, "${params.username}"
    WHERE NOT EXISTS 
        (SELECT * FROM song_artist WHERE id_song = ${params.id} AND artist = "${params.username}");`
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                mysql_main.query_execute(db, query2)
                    .then((result2) => {
                        resolve(result);
                    })
            })
    })
}
module.exports.update_song = (db, params) =>{
    query =
        `UPDATE songs SET
            title_song = "${params.title}"
         WHERE id_song = ${params.id};`;
    query2 =
        `INSERT INTO song_artist (id_song, artist)
    SELECT ${params.id}, "${params.username}"
    WHERE NOT EXISTS 
        (SELECT * FROM song_artist WHERE id_song = ${params.id} AND artist = "${params.username}");`;
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, query)
            .then((result) => {
                mysql_main.query_execute(db, query2)
                    .then((foo) => {
                        resolve(result);
                    })
            })
    })

}
module.exports.delete_song = (db, params) =>{
    query =
        `DELETE FROM songs
         WHERE id_song = ${params.id};`;
    foreignChecks = ["SET FOREIGN_KEY_CHECKS=OFF;", "SET FOREIGN_KEY_CHECKS=ON;"];
    return new Promise(function (resolve, reject) {
        mysql_main.query_execute(db, foreignChecks[0])
            .then((foreign1) => {
                mysql_main.query_execute(db, query)
                    .then((result) => {
                        mysql_main.query_execute(db, foreignChecks[1])
                            .then((foreign2) => {
                                resolve(result);
                            })
                    })
            })
    })

}