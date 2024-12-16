<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>start with if or not</title>
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
    if (str_starts_with($str, 'if')) {
        echo "<br> string : $str "; 
    }
    else{
        $str = "if" + $str;
        echo "<br> new string : $str "; 
    }

    ?>     
</div>
</body>
</html>