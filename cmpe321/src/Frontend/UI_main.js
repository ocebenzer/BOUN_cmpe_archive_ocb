const express = require("express");
const mysql_calls = require("../MySQL/MySQL_calls");
const mysql = require("../MySQL/MySQL_main");
const db = mysql.connect_db("dbtify");
module.exports.create_server = create_server;

function create_server(port) {
    const server = express();
    server.get("/", (req,res) =>{
        res.sendFile("./menu.html", {root: __dirname+"\\..\\..\\templates"});
    });
    server.get("/api/is_listener/:name", (req, res) =>{
        mysql_calls.is_listener(db, req.params.name)
            .then(result => {
                res.send(result);
            });
    })
    server.get("/api/is_artist/:name", (req, res) =>{
        mysql_calls.is_artist(db, req.params.name)
            .then(result => {
                res.send(result);
            });
    })

    server.get("/api/songs", (req,res) =>{
        mysql_calls.get_songs(db)
            .then(result =>{
                res.send(result);
            })
    })
    server.get("/api/albums", (req,res) =>{
        mysql_calls.get_albums(db)
            .then(result =>{
                res.send(result);
            })
    })
    server.get("/api/artists", (req,res) =>{
        mysql_calls.get_artists(db)
            .then(result =>{
                res.send(result);
            })
    })
    server.get("/api/listeners", (req,res) =>{
        mysql_calls.get_listeners(db)
            .then(result =>{
                res.send(result);
            })
    })

    server.get("/api/song/:id", (req,res) =>{
        mysql_calls.get_song(db, req.params.id)
            .then(song =>{
                mysql_calls.song_get_artists(db, req.params.id)
                    .then(artists =>{
                        res.send({"song":song,"artists":artists});
                    })
            })
    })
    server.get("/api/album/:id", (req,res) =>{
        mysql_calls.get_album(db, req.params.id)
            .then(album =>{
                mysql_calls.album_get_songs(db, req.params.id)
                    .then(songs =>{
                        mysql_calls.album_get_artists(db, req.params.id)
                            .then(artists =>{
                                res.send({"album":album,"songs":songs, "artists":artists});
                            })
                    })
            })
    })
    server.get("/api/artist/:name", (req,res) =>{
        mysql_calls.get_artist(db, req.params.name)
            .then(artist =>{
                mysql_calls.artist_get_songs(db, req.params.name)
                    .then(songs =>{
                        mysql_calls.artist_get_albums(db, req.params.name)
                            .then(albums =>{
                                mysql_calls.artist_get_artists(db, req.params.name)
                                    .then(artists =>{
                                        res.send({"artist":artist,"songs":songs,"albums":albums, "artists": artists[0]});
                                    })
                            })
                    })
            })
    })

    server.get("/api/liked_songs/:username", (req,res) =>{
        mysql_calls.listener_get_liked_songs(db, req.params.username)
            .then(result =>{
                res.send(result);
            })
    })
    server.get("/api/liked_albums/:username", (req,res) =>{
        mysql_calls.listener_get_liked_albums(db, req.params.username)
            .then(result =>{
                res.send(result);
            })
    })
    // Search routes


    server.get("/api/search_genre/:keyword", (req,res) =>{
        mysql_calls.listener_search_genre(db, req.params.keyword)
            .then(result =>{
                res.send(result);
            })
    })
    server.get("/api/search_title/:keyword", (req,res) =>{
        mysql_calls.listener_search_title(db, req.params.keyword)
            .then(result =>{
                res.send(result);
            })
    })

    // Like routes

    server.get("/api/like_song/:username/:id", (req,res) =>{
        mysql_calls.listener_like_song(db, req.params.username, req.params.id)
            .then(result =>{
                res.send(result);
            })
    })

    server.get("/api/like_album/:username/:id", (req,res) =>{
        mysql_calls.listener_like_album(db, req.params.username, req.params.id)
            .then(result =>{
                res.send(result);
            })
    })

    // Artist actions
    //Album
    server.get("/api/add_album/:id/:username/:genre/:title", (req,res) =>{
        mysql_calls.add_album(db, req.params)
            .then(result =>{
                res.send(result);
            })
    })
    server.get("/api/update_album/:id/:username/:genre/:title", (req,res) =>{
        mysql_calls.update_album(db, req.params)
            .then(result =>{
                res.send(result);
            })
    })
    server.get("/api/delete_album/:id", (req,res) =>{
        mysql_calls.delete_album(db, req.params)
            .then(result =>{
                res.send(result);
            })
    })
    //Song

    server.get("/api/add_song/:username/:id/:album/:title", (req,res) =>{
        mysql_calls.add_song(db, req.params)
            .then(result =>{
                res.send(result);
            })
    })
    server.get("/api/update_song/:username/:id/:title", (req,res) =>{
        mysql_calls.update_song(db, req.params)
            .then(result =>{
                res.send(result);
            })
    })
    server.get("/api/delete_song/:id", (req,res) =>{
        mysql_calls.delete_song(db, req.params)
            .then(result =>{
                res.send(result);
            })
    })
    server.listen(port);
    console.log("Listening on Port " + port);
    return server;
}
