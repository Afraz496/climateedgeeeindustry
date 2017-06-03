<?php
$host = "localhost";
$db_user = "afrazinator";
$db_password = "password";
$db_name = "user_db";

$con = mysqli_connect($host,$db_user,$db_password,$db_name);
if($con){
  echo "Connection Success...";
}
else{
  echo "Connection Failed...";
}
?>
