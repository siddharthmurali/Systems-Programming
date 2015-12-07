<?php
$servername = "databases.casvcfhpchqi.us-west-2.rds.amazonaws.com";
$username = "cs336";
$password = "prininfo";
$dbname = "CS336";
$id = $_GET['groupID'];
$arg1 = $argv[1];


// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);
// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$sql = " SELECT Name FROM laptopdata WHERE Manufacturer = '$id' ";

$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    // output data of each row
    
    $rows = array();
    
    while($r = mysqli_fetch_assoc($result)) {
        
        $rows[] = $r;
        echo $r[Name]. "\n";
    }
    
    //echo json_encode($rows);
    
    
} else {
    echo "0 results";
}


mysqli_close($conn);
?>

