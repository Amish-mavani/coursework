<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>marks</title>
    
</head>
<body>
<div>
    <h4>enter the marks</h4>
    <form action="" method="post">
        <input type="marks" name="marks" value="0" />
        <input type="submit" name="submit" value="Submit" />
	</form>       
</div>
<?php
    $m = $_POST['marks'];
    if ($m > 60)
    {
        echo " your grade will be First Division.";
    }
    else
    {
        if ($m < 59 && $m > 45)
        {
            echo " your grade will be Second Division.";
        }
        else
        {
            if ($m < 44 && $m > 33)
            {
                echo " your grade will be Third Division.";
            }
            else
            {
                echo " you will be Fail..";
            }
        }
    }
    ?> 
    
</body>
</html>




