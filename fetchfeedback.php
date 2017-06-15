<?php

$user = "root";
$password = "";
$host = "localhost";
$db_name = "feedback";

$con = mysqli_connect($host,$user,$password,$db_name) or die('Unable to connect');

if($_SERVER['REQUEST_METHOD'] == 'GET'){
  $type = $_GET['type'];
  $sql = "SELECT * FROM climate_edge_feedback WHERE type='".$type."'";

  $r = mysqli_query($con,$sql);
  $res = mysqli_fetch_array($r);

  $result = array();

  array_push($result,array(
    "type"=>$res['type'],
    "feedback"=>$res['feedback']
    ));

  echo json_encode(array("result"=>$result));

  mysqli_close($con);

}
?>
