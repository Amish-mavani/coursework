<?php
$color = array('white', 'green', 'red');
$len = sizeof($color);

for($i=0;$i<$len;$i++){
    echo "$color[$i],";
}
echo "<br>";
foreach ($color as $c)
{
echo "<br>$c";
}

echo "<br><ul>";
foreach ($color as $y)
{
echo "<li>$y</li>";
}
echo "</ul>";
?>