<?php
function show($result)
{
	echo '<table class="lighting" border=1>';  
	echo '<tr class="up_row"><th>№</th>'; 
	echo '<th>Учётный номер</th>';  
	echo '<th>Код модели</th>'; 
	echo '<th>Тип процессора</th>'; 
	echo '<th>Размер диска</th>'; 
	echo '<th>Объём памяти</th>';
	echo '<th>Изменить данные</th>';
	echo '<th>Удалить данные</th></tr>'; 
 
	while ($row = mysqli_fetch_array ($result))  
	{  
		echo '<tr><td>'.$row['id'];
		echo '</td><td>'.$row['reg_num'];  
		echo '</td><td>'.$row['model_code'];
		echo '</td><td>'.$row['processor_type'];		
		echo '</td><td>'.$row['disk_size'];
		echo '</td><td>'.$row['memory_size'];
		echo '</td>';
		echo '<td><form action="phpdatatable.php" method="post">'; 
		echo '<input  type="hidden"  name="id"  value="'.$row['id'].'">';  
		echo '<input align="bottom" type="submit" value="Изменить">'; 
		echo '</form></td>';
		echo '<td><form action="processdel.php" method="post">'; 
		echo '<input  type="hidden"  name="id"  value="'.$row['id'].'">';  
		echo '<input align="center" type="submit" value="Удалить">'; 
		echo '</form></td>';	
		echo '</tr>';		
	} 
echo "</table>";
	
}

function searching($search)
{
	$connection = mysqli_connect("localhost", "root", "", "dbase_pc") 
	or die ("Ошибка соединения с сервером"); 
	$search = $_POST['search'];
	$query = "SELECT pc.id as id, 
				pc.reg_num as reg_num, 
				pc.model_code as model_code,
				pc.processor_type as processor_type, 
				pc.disk_size as disk_size, 
				sizeset.nums as memory_size
				FROM pc INNER JOIN sizeset ON pc.memory_size = sizeset.id
			  WHERE 
			  pc.id LIKE '%$search%' || 
			  reg_num LIKE '%$search%' || 
			  processor_type LIKE '%$search%'";
	$result = mysqli_query ($connection, $query) or die ("Ошибка при выполнении запроса ".mysqli_errno ($connection).": ".mysqli_error ($connection));
	mysqli_close($connection); 
	return $result;
}

?>