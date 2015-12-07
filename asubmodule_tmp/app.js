var express = require('express');
var app = express();
var bodyParser = require('body-parser');

var mysql = require('mysql');
 
var connection = mysql.createConnection(
    {
      host     : 'databases.casvcfhpchqi.us-west-2.rds.amazonaws.com',
      user     : 'cs336',
      password : 'prininfo',
      database : 'CS336',
    }
);
 

app.use(express.static(__dirname + '/css'));
app.use(express.static(__dirname + '/js'));
app.use(express.static(__dirname + '/pics'));
app.use(bodyParser.urlencoded({
    extended: true
}));
app.use(bodyParser.json());


connection.connect();
 
var resultApple = [];
var resultDell = [];
var resultHP = [];
var resultAsus = [];
var resultAcer = [];
var resultLenovo = [];
var resultGateway = [];
var resultToshiba= [];
var resultSamsung= [];
var resultAlienware = [];
var resultIBM = [];
var resultCS = [];
var resultsAppleBuyers = [];




//Query Strings

var queryStringApple = 'SELECT Name FROM laptopdata WHERE Manufacturer = "Apple" ';

connection.query(queryStringApple, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        resultApple[i] = rows[i];
    }
});
var queryStringSamsung = 'SELECT Name FROM laptopdata WHERE Manufacturer = "Samsung" ';

connection.query(queryStringSamsung, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        resultSamsung[i] = rows[i];
    }
});
var queryStringToshiba = 'SELECT Name FROM laptopdata WHERE Manufacturer = "Toshiba" ';

connection.query(queryStringToshiba, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        resultToshiba[i] = rows[i];
    }
});
var queryStringIBM = 'SELECT Name FROM laptopdata WHERE Manufacturer = "IBM" ';

connection.query(queryStringIBM, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        resultIBM[i] = rows[i];
    }
});
var queryStringHP = 'SELECT Name FROM laptopdata WHERE Manufacturer = "HP" ';

connection.query(queryStringHP, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        resultHP[i] = rows[i];
    }
});
var queryStringLenovo = 'SELECT Name FROM laptopdata WHERE Manufacturer = "Lenovo" ';

connection.query(queryStringLenovo, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        resultLenovo[i] = rows[i];
    }
});
var queryStringGateway = 'SELECT Name FROM laptopdata WHERE Manufacturer = "Gateway" ';

connection.query(queryStringGateway, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        resultGateway[i] = rows[i];
    }
});
var queryStringAsus = 'SELECT Name FROM laptopdata WHERE Manufacturer = "Asus" ';

connection.query(queryStringAsus, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        resultAsus[i] = rows[i];
    }
});
var queryStringAcer = 'SELECT Name FROM laptopdata WHERE Manufacturer = "Acer" ';

connection.query(queryStringAcer, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        resultAcer[i] = rows[i];
    }
});
var queryStringDell = 'SELECT Name FROM laptopdata WHERE Manufacturer = "Dell" ';

connection.query(queryStringDell, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        resultDell[i] = rows[i];
    }
});
var queryStringAlienware = 'SELECT Name FROM laptopdata WHERE Manufacturer = "Alienware" ';

connection.query(queryStringAlienware, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        resultAlienware[i] = rows[i];
    }
});

var queryStringCS = 'SELECT Manf FROM buys WHERE Job = "computer scientist" ';

connection.query(queryStringCS, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        resultCS[i] = rows[i];
    }
});

var queryStringAppleBuyers = 'SELECT Job FROM buys WHERE Manf = "Apple" ';

connection.query(queryStringAppleBuyers, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        resultsAppleBuyers[i] = rows[i];
    }
});


app.get('/', function (req, res) {
    res.sendFile("index.html", {"root": __dirname});
});

app.get('/', function (req, res) {
    res.sendFile("proj.html", {"root": __dirname});
});

app.get('/', function (req, res) {
    res.sendFile("team.html", {"root": __dirname});
});

app.get('/getApple', function (req, res) {
    res.send(resultApple);
});
app.get('/getLenovo', function (req, res) {
    res.send(resultLenovo);
});
app.get('/getDell', function (req, res) {
    res.send(resultDell);
});
app.get('/getHP', function (req, res) {
    res.send(resultHP);
});
app.get('/getGateway', function (req, res) {
    res.send(resultGateway);
});
app.get('/getIBM', function (req, res) {
    res.send(resultIBM);
});
app.get('/getAsus', function (req, res) {
    res.send(resultAsus);
});
app.get('/getAcer', function (req, res) {
    res.send(resultAcer);
});
app.get('/getAlienware', function (req, res) {
    res.send(resultAlienware);
});
app.get('/getToshiba', function (req, res) {
    res.send(resultToshiba);
});
app.get('/getSamsung', function (req, res) {
    res.send(resultSamsung);
});
app.get('/getCS', function (req, res) {
    res.send(resultCS);
});
app.get('/getAppleBuyers', function (req, res) {
    res.send(resultsAppleBuyers);
});



var server = app.listen(3000, function () {
  var host = server.address().address;
  var port = server.address().port;

  console.log('Example app listening at http://%s:%s', host, port);
});
