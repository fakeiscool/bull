<html>  
<HEAD> 
    <title>Изменение данных оборудования</title> 
    <meta charset="utf-8"> 
</HEAD>  
<h2 align="center">Измените данные</h2> 
<body > 
    <form action="processedit.php" method="post"> 
    <table border=0 align="center"> 
<tr bgcolor=#cccccc> 
<td> 
<td> 

<?php 
	$id = $_POST['id'];
	echo '<input type="hidden" name="id" value="'.$id.'">'; 
	
	$connection = mysqli_connect("localhost", "root", "", "dbase_pc")	
	or die ("Ошибка соединения с сервером");
	
	$query = "SELECT reg_num,    
        model_code,
		processor_type,
		disk_size,
		memory_size
        FROM pc 
                WHERE id='$id'"; 
	
	$result = mysqli_query ($connection, $query) 
	or die ("Ошибка при выполнении запроса ".mysqli_errno ($connection).": ".mysqli_error ($connection));
	
	$row=mysqli_fetch_array($result); 
	
	echo '<tr> 
        <td>Учётный номер<td align=left> 
        <input  type="text"  name="reg_numadd" size="40" maxlength="30" 
		value="'.$row['reg_num'].'"></td></tr>'; 
    echo '<tr> 
        <td>Код модели<td align=left> 
        <input  type="int"  name="model_codeadd" size="40" 
		value="'.$row['model_code'].'"></td></tr>'; 
    echo '<tr> 
        <td>Тип процессора<td align=left> 
        <input  type="text"  name="processor_typeadd" size="40"
		value="'.$row['processor_type'].'"></td></tr>'; 
    echo '<tr> 
        <td>Размер диска<td align=left> 
        <input  type="text"  name="disk_sizeadd" size="40"
		value="'.$row['disk_size'].'"></td></tr>'; 
    echo '<tr> 
        <td>Объём памяти<td align=left><select name="memory_sizeadd">'; 
	$query2 = "SELECT * FROM sizeset"; 
	$result = mysqli_query($connection, $query2) or  die  ("Ошибка  при  выполнении  запроса ".mysqli_errno ($connection).": ".mysqli_error($connection)) ; 				
	while($object = mysqli_fetch_array($result)){ 
		if ($object['id'] == $row['memory_size'])  
		{  
		echo '<option selected value="'.$object['id'].'" >' .$object['nums'].'</option>'; 
		}else{   
		echo '<option value ="'.$object['id'].'" >' .$object['nums'].'</option>';  
		} 
	} 
	echo '</select></td></tr>';
    mysqli_close($connection); 
	
	
?> 
<tr><td colspan="7" align="center"><input type="submit" name="vvod" 
	value="Изменить"></td></tr> 

    </table> 
    </form> 
</body>  
</html> 