const express = require("express");
const mysql = require("mysql");
const mysql_pw = require("../utils/password");
module.exports.connect_db = connect_db;
module.exports.query_execute = query_execute;

function connect_db(name) {
    //DB Create connection
    const db = mysql.createConnection({
        host     : 'localhost',
        user     : 'root',
        password : mysql_pw.root,
        database : name

    });

    //DB Connect
    db.connect((err)=> {
        if(err) console.log (err);
        else console.log("-> MySql Connected");
    })
    const app = express();

    //DB Initialize
    //mysql_init.init(db, "dbtify")
    return db;
}
function query_execute(db, query) {
    return new Promise(function (resolve, reject) {
        db.query(query, (err, result)=>{
            if(err) {
                reject(err);
            }
            else{
                console.log("-> Query answered");
                console.log(result);
                resolve(result);
            }
        })
    });
}