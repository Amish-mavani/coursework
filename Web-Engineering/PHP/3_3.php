<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Factorial</title>
    <?php 
    function Factorial($number){ 
    $factorial = 1; 
    for ($i = 1; $i <= $number; $i++){ 
    $factorial = $factorial * $i; 
    } 
    return $factorial; 
    } 

    $number = $_POST['number'];
    $fact = Factorial($number); 
    echo "Factorial = $fact"; 
?> 
</head>
<body>
<div>
    <h4>enter a number to find factorial </h4>
    <form action="" method="post">
        <input type="number" name="number" />
        <input type="submit" name="submit" value="Submit" />
	</form>       
</div>
    
</body>
</html>






