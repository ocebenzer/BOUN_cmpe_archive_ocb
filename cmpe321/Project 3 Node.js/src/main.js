const mysql = require("./MySQL/MySQL_main");
const UI = require("./Frontend/UI_main");

//Connect DB
const db = mysql.connect_db("dbtify");
module.exports.db = db;
//Create Web Server
let server = UI.create_server(3000);
