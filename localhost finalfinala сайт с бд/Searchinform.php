<html> 
    <head> 
        <meta charset="utf-8"> 
		<title>Поиск оборудования</title>
    </head> 
    <body> 
	<h1 align="center" >Список оборудования</h1>
<?php
	$seacrh = $_POST['search'];
	require 'Showtable.php';
	$result = searching($search);
	show($result);
?>  
	
</body>
</html> 