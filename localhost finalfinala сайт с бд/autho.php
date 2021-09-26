<?php
	header('Content-Type: text/html');
	$username = '123';
	$pass = '123';
	if (!isset($_SERVER['PHP_AUTH_USER']) || !isset($_SERVER['PHP_AUTH_PW']) || ($_SERVER['PHP_AUTH_USER'] != $username) || ($_SERVER['PHP_AUTH_PW'] != $pass)){
		header('HTTP/1.1.401 Unauthorized'); 
		header('WWW-Authenticate: Basic realm ="Оборудования"');
		exit('Вы должны ввести правильно имя пользователя и пароль');
	}
	else { header('Location: grupedit.php'); }
?>