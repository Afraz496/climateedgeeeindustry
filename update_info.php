<?php

$user_name = $_POST["name"];
$user_pass = $_POST["email"];

$user = "root";
$password = "";
$host = "localhost";
$db_name = "user_db";

$con = mysqli_connect($host,$user,$password,$db_name);

$sql = "insert into user_info values('".$user_name."','".$user_pass."');";

if(mysqli_query($con,$sql)){
  echo "successfully sent data to the server";
}
else{
  echo "Error while insertion...";
}

mysqli_close($con);

?>
