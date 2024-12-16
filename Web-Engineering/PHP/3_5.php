<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Electricity bill</title>
    <?php
    $m = $_POST['unit'];

    function calculate_bill($unit) {
        $first = 3.50;
        $second = 4.00;
        $third = 5.20;
        $fourth = 6.50;
    
        if($unit <= 50) {
            $bill = $unit * $first;
        }
        else if($unit > 50 && $unit <= 100) {
            $temp = 50 * $first;
            $remaining_unit = $unit - 50;
            $bill = $temp + ($remaining_unit * $second);
        }
        else if($unit > 100 && $unit <= 200) {
            $temp = (50 * 3.5) + (100 * $second);
            $remaining_unit = $unit - 150;
            $bill = $temp + ($remaining_unit * $third);
        }
        else {
            $temp = (50 * 3.5) + (100 * $second) + (100 * $third);
            $remaining_unit = $unit - 250;
            $bill = $temp + ($remaining_unit * $fourth);
        }
        return number_format((float)$bill, 2, '.', '');
    }
    $result = calculate_bill($m);
    echo "Total amount of  $m units is $result ";
    
    ?>
</head>
<body>
<div>
		<h1>Electricity Bill</h1>
        <h4>enter the value of unit</h4>
		<form action="" method="post">
            <input type="number" name="unit" />
            <input type="submit" name="submit" value="Submit" />
		</form>
	</div>
</body>
</html>