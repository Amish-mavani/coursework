<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>lower string</title>

</head>
<body>
<div>
    <h4>enter a string </h4>
    <form action="" method="post">
        <input type="text" name="text" />
        <input type="submit" name="submit" value="Submit" />
	</form>       
</div>
<?php  
function checkChars($str) { 
    $upperCase = preg_match('/[A-Z]/', $str); 
    $lowerCase = preg_match('/[a-z]/', $str); 
    $specialChar = preg_match('/[^A-Za-z0-9]/', $str); 
    $numericVal = preg_match('/[0-9]/', $str); 
    
    if($lowerCase != 0  && $upperCase == 0 && $specialChar == 0 && $numericVal == 0){
        echo "<br> it cantain only contains lowercase ";
    }else
    {
        if($lowerCase != 0){
            echo "<br> it contain lowercase ";
        }else
        {
            echo "";
        }
    
        if($upperCase != 0){
            echo "<br> it contain Uppercase ";
        }else
        {
            echo "\n";
        }
        if($specialChar != 0){
            echo "<br> it contain Special Characters ";
        }else
        {
            echo "\n";
        }
    
        if($numericVal != 0){
            echo "<br> it contain Numeric Values ";
        }else
        {
            echo "\n";
        }
    } 
} 

$str = $_POST['text']; 
$result = checkChars($str);  
?>   
</body>
</html>






