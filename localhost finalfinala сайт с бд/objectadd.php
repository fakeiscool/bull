<html>  
<HEAD> 
    <title>Добавление оборудования</title> 
    <meta charset="utf-8"> 
</HEAD>  
<h2 align="center">Введите данные</h2> 
<body >
<?php
	$connection = mysqli_connect("localhost", "root", "", "dbase_pc") or die ("Ошибка соединения с сервером");
	$query = "SELECT * FROM sizeset"; 
	$result = mysqli_query($connection, $query) 
		or  die  ("Ошибка  при  выполнении  запроса ".mysqli_errno ($connection).": ".mysqli_error 
	($connection)) ;
	//echo $result[1];
?> 
    <form action="phpdatainsert.php" method="post"> 
    <table border=0 align="center"> 
    <tr bgcolor=#cccccc> 
        <td><td> 
        <tr><td class="t2">Введите учётный номер</td> 
        <td> <input type="text" size="40" maxlength="30" name="reg_num"></td></tr> 
        <tr><td class="t2">Введите номер модели</td> 
        <td> <input type="text" size="40" maxlength="11" name="model_code"></td></tr>
		<tr><td class="t2">Введите тип процессора</td> 
        <td> <input type="text" size="40" maxlength="11" name="processor_type"></td></tr>
		<tr><td class="t2">Введите размер диска</td> 
        <td> <input type="text" size="40" maxlength="11" name="disk_sizebd"></td></tr>
		
       <tr><td class="t2">Введите размер памяти</td> 
        <td><select name="memory_sizebd">
		<?php
			$query = "SELECT * FROM sizeset"; 
			$result = mysqli_query($connection, $query)	or  die  ("Ошибка  при  выполнении  запроса ".mysqli_errno ($connection).": ".mysqli_error ($connection)) ;
			echo '<option selected value = 0 disabled> Выберите размер памяти</option>';
			while($object = mysqli_fetch_array($result)){  
				echo '<option value ="'.$object['id'].'" >' .$object['nums'].'</option>';  
			}
			mysqli_close($connection);			
		?>
		</select>
		</td></tr>
		<td><td>
        <tr><td  colspan="2"  align="center"><input type="submit" name="vvod" 
value="Отправить"></td></tr> 
    </table> 
</body>  
</html> 
