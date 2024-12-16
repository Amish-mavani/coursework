<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>replace the with that</title>
</head>
<body>
<div>
    <h4>enter a string : </h4>
    <form action="" method="post">
        <input type="text" name="string" />
        <input type="submit" name="submit" value="Submit" />
	</form>  
    <?php 
    $str = $_POST['string'];
    if (str_starts_with($str, 'the')) {
        $str = str_replace('the', 'that', $str); 
        echo "<br> new string : $str "; 
    }
    else{
        echo "<br> enter another string that start with the ";
    }

    ?>     
</div>
</body>
</html>