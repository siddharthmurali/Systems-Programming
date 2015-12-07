<?php  	

$id = $_GET['id'];
	try {  		

		$con = new PDO("mysql:host=databases.casvcfhpchqi.us-west-2.rds.amazonaws.com;dbname=CS336",  "cs336","prininfo",array(PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8") );
  	
		}

	  	catch (PDOException $e) {

	  		echo "Sorry, there was an error connecting to the database.\n"; 	

			}
		  	  	

		if (isset($_GET["id"])) {
		
			$stmt = $con->prepare("select name from foods where groupid = '$id' ");
            //$stmt->bindValue(1,$_GET[]);
  

			// Fetch the foods using the group id 
			if ($stmt->execute()) {
                $result = $stmt->fetchAll(PDO::FETCH_ASSOC); 			  		

				// If there are results, json encode them as the reply.  			
				if ($result) {  				

					echo json_encode($result);  			

				}  		

			}  	

		}  

?>
