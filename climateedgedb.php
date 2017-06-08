<?php

$user_tag = $_POST["tag"];
$user_val = $_POST["value"];

$user = "root";
$password = "";
$host = "localhost";
$db_name = "climateedge_db";

$con = mysqli_connect($host,$user,$password,$db_name);

$sql = "insert into sensor_data values('".$user_tag."','".$user_val."');";

if(mysqli_query($con,$sql)){
  echo "successfully sent data to the server";
}
else{
  echo "Error while insertion...";
}

mysqli_close($con);

?>
