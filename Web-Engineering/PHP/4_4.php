<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>check email validation</title>
</head>
<body>
<div>
    <h4>enter a email : </h4>
    <form action="" method="post">
        <input type="text" name="string" />
        <input type="submit" name="submit" value="Submit" />
	</form>  
    <?php 
    $str = $_POST['string'];
    if (str_contains($str, '@')) {
        if (str_contains($str, '.')){
            echo "<br> email $str is valid. ";
        }
        else{
            echo "<br> email $str is invalid. ";
            echo "<br> alert : '.' is missing .";
        }
    }
    elseif(str_contains($str, '.')) {
        if (str_contains($str, '@')){
            echo "<br> email $str is invalid. ";
        }
        else{
            echo "<br> email $str is invalid. ";
            echo "<br> alert : '@' is missing .";
        }
    }
    else{
        echo "<br> email $str is invalid. ";
        echo "<br> alert : '@' and '.' are missing .";
    }

    ?>     
</div>
</body>
</html>