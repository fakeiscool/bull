<html> 
    <head> 
        <meta charset="utf-8"> 
		<title>Учёт оборудования</title>
    </head> 
    <body> 
	
	
	<h1 align="center" >Список оборудования</h1>
	<form action="index.php" method="post">
	<table border=0> 
		<tr bgcolor=#cccccc> 
		  <td width="150"> </td>       
		 <td width="15"> </tr></td>
		 <tr> 
		  <td>Поиск</td>
		  <td colspan="2"><input type="hidden" name="confirm" id="confirm" value="12345"></td>
		  <td align="left"><input type="text" name="search" size="30" maxlength="30"> </td>
		  <td col span="1" align="center"><input type="submit" value="Поиск"></td> 
		 </tr>
	</table>
	</form>
<?php
	if($_POST["confirm"])
	{
		$seacrh = $_POST['search'];
		require 'Showtable.php';
		$result = searching($search);
		show($result);	
	}
	else
	{
		$connection = mysqli_connect("localhost", "root", "", "dbase_pc") 
		or die ("Ошибка соединения с сервером"); 
		$query = "SELECT pc.id as id, 
				pc.reg_num as reg_num, 
				pc.model_code as model_code,
				pc.processor_type as processor_type, 
				pc.disk_size as disk_size, 
				sizeset.nums as memory_size
				FROM pc INNER JOIN sizeset ON pc.memory_size = sizeset.id ORDER BY id"; 
		$result = mysqli_query ($connection, $query) 
		or die ("Ошибка при выполнении запроса ".mysqli_errno ($connection).": ".mysqli_error ($connection)); 
		require 'Showtable.php';
		show($result);	
		mysqli_close($connection); 
	}
?> 

<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script> 

 <style type="text/css"> 
 .lighting { width: 100%; border-collapse: collapse; border: 2px solid #000000; } 
 .lighting tr { text-align: center; font-weight: bold; line-height: 2; } 
 .lighting tr td { border: 1px solid #503030; } 
 .lighting .up_row { background-color: #6E6E6E; color: #FFFFFF; }
 .lighting_col { background-color: #D4D4D4; } 
 .lighting_cell { background-color: #667E96; color: #FFFFFF; } 
</style> 


<script type="text/javascript"> 
$(document).ready(function(){ 
$(".lighting td").on("mouseenter mouseleave", function(){ 
    if ($(this).parents(".lighting tr").attr("class")!="up_row") { 
        var td_index=$(this).index(); 
        $(this).parents("tr").toggleClass("lighting_col"); 
        $(this).parents(".lighting").find("tr:not(.up_row)").each(function(){ 
            $("td:eq("+td_index + ")",this).toggleClass("lighting_col"); 
        }); 
        $(this).toggleClass("lighting_cell"); 
    } 
}); 
}); 
</script>




<p><a href='objectadd.php'>Добавить</a>
<p><a href='autho.php'>Редактировать группы</a>

</body>
</html> 