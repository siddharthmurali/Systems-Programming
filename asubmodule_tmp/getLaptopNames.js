var mysql = require('mysql');
 
var connection = mysql.createConnection(
    {
      host     : 'databases.casvcfhpchqi.us-west-2.rds.amazonaws.com',
      user     : 'cs336',
      password : 'prininfo',
      database : 'CS336',
    }
);
 
connection.connect();
 
var queryString = 'SELECT Name FROM laptopdata WHERE Manufacturer = "Apple" ';
 
connection.query(queryString, function(err, rows, fields) {
    if (err) throw err;
 
    for (var i in rows) {
        
        console.log(rows[i]);
    }
});
 
connection.end();

