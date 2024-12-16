<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Inserting some data</title>
</head>
<body>
<div>
	<h1>Inserting some data into person through HTML form.</h1>
	<form action="" method="post">
        <h4>enter the id</h4>
        <input type="number" name="id"/>
        <h4>enter the first name</h4>
        <input type="text" name="fname"/>
        <h4>enter the last name</h4>
        <input type="text" name="lname"/>
        <h4>enter the email</h4>
        <input type="text" name="email"/>
  <br><h1>selecting some data from person through HTML form</h1>
        <h4>enter the id</h4>
        <input type="number" name="id1"/>
  <br><h1>updateing some data into person through HTML form.</h1>
        <h4>enter the old id</h4>
        <input type="number" name="ido2"/>
        <h4>enter the new id</h4>
        <input type="number" name="idn2"/>
        <h4>enter the first name</h4>
        <input type="text" name="fname2"/>
        <h4>enter the last name</h4>
        <input type="text" name="lname2"/>
        <h4>enter the email</h4>
        <input type="text" name="email2"/>
        <br><br><input type="submit" name="submit" value="Submit" />
	</form>
</div>

<?php
$servername = "localhost";
$username = "root";
$password = "Amish@4929";
$dbname = "my_db";

$conn = new mysqli($servername, $username, $password);
if ($conn->connect_error) {
  die(" <br> Connection failed: <br>" . $conn->connect_error);
}
echo "<br> Connected successfully <br>";

$sql = "CREATE DATABASE IF NOT EXISTS my_db";
if (mysqli_query($conn, $sql)) {
  echo "<br> Database created successfully <br>";
} else {
  echo "<br> Error in creating database <br> " . $conn->error;
}

mysqli_close($conn);

$dbname = "my_db";
$conn = new mysqli($servername, $username, $password, $dbname);

$sql = "CREATE TABLE IF NOT EXISTS person ( id INT(6)  PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30), email VARCHAR(50))";
if ($conn->query($sql) === TRUE) {
    echo "<br> Table created successfully <br>";
  } else {
    echo "<br> Error creating table: <br>" . $conn1->error;
  }  

$sql = "INSERT INTO person (id, firstname, lastname, email) VALUES ('37','Amish', 'Mavani', 'nswnkwna.com')";
if ($conn->query($sql) === TRUE) {
    echo "<br> inserted data successfully <br> ";
  } else {
    echo "<br> Error in inserting data in table: <br> " . $conn1->error;
  }  

if(!($_POST['id'])){
  echo "<br> there is no insertion of data.";
} else {
  $id = $_POST['id'];
  $fname = $_POST['fname'];
  $lname = $_POST['lname'];
  $email = $_POST['email'];
  $sql = "INSERT INTO person (id, firstname, lastname, email) VALUES ('$id', '$fname', '$lname', '$email')";
  if($conn->query($sql) === TRUE){
      echo "<br> inserted data successfully <br> ";
    } 
  else {
      echo "<br> Error in inserting data in table: <br> " . $conn->error;
  } 
}

$id1 = $_POST['id1'];
if(!($id1))
{
  echo "<br><br> 0 results : nothing selected <br>";
} else {
  $sql= "SELECT * FROM person WHERE id = '$id1' ";
  $result = $conn->query($sql);
  if ($result->num_rows > 0) {
  while($row = $result->fetch_assoc()) {
    echo "<br><br>id: " . $row["id"]. " - Name: " . $row["firstname"]. " " . $row["lastname"]. "  email : " . $row["email"]. "<br>";
  }
  } else {
     echo "<br><br> 0 results <br>";
  }
}

if(!($_POST['ido2'])){
  echo "<br> there is no updation of data.<br>";
} else {
  $old = $_POST['ido2'];  
  $id = $_POST['idn2'];
  $fname = $_POST['fname2'];
  $lname = $_POST['lname2'];
  $email = $_POST['email2'];
  $sql = " UPDATE person SET id = '$id', firstname = '$fname', lastname = '$lname', email = '$email' WHERE id = ' $old ' ";
  if($conn->query($sql) === TRUE){
      echo "<br> inserted data successfully <br>";
    } 
  else {
      echo "<br> Error in inserting data in table: <br>" . $conn->error;
  } 
}

$sql= "SHOW DATABASES ";
$result = $conn->query($sql);
echo "<br><br><b> : DATABASES : </b>";
while ($row = $result->fetch_assoc()) {
  //print_r($row);
  echo "<br>" . $row["Database"] ;
}

$sql= "SHOW TABLES ";
$result = $conn->query($sql);
echo "<br><br><b> : TABLES : </b>";
while ($row = $result->fetch_assoc()) {
  //print_r($row);
  echo "<br>" . $row["Tables_in_my_db"] ;
}

mysqli_close($conn);
?>
</body>
</html>