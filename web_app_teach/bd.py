import sqlite3

from werkzeug.security import * # тоже обязательно нужно импортировать для хэширования данных
from users import *

class Database:
    def init(self):
        connection = self.connect_db()  # подключение к бд
        cursor = connection.cursor()
        try:
            cursor.execute("""CREATE TABLE IF NOT EXISTS pc( 
                    id INTEGER PRIMARY KEY AUTOINCREMENT, 
                    reg_num INTEGER,
                    processor_type VARCHAR,
                    disk_size INTEGER,
                    memory_size INTEGER REFERENCES memory_set(id)
                );""")
            # SQl код создания основной таблицы с внешним ключем

            cursor.execute("""CREATE TABLE IF NOT EXISTS memory_set (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    num INTEGER UNIQUE
                );""")  # SQL код создания таблицы помощника, которая имеет часто повторяемые данные
            # SQL код создания таблицы помощника, которая имеет часто повторяемые данные
            cursor.executemany("""INSERT OR IGNORE INTO memory_set (num) VALUES (?);""",
                               [(1024,), (2048,), (4096,), (8192,), (16384,), (32768,), (65536,)])
            cursor.execute("""CREATE TABLE IF NOT EXISTS users (
                login TEXT PRIMARY KEY,
                password TEXT
            );""")

            hashed_password = generate_password_hash('admin', method='pbkdf2:sha256')
            cursor.execute("INSERT OR IGNORE INTO users (login, password) VALUES (?, ?)", ('admin', hashed_password))

            connection.commit()
            # print("БД успешно создана.")
        except Exception as e:
            print(f"Ошибка создания БД: {e}")
        finally:
            connection.close()

    # функция подключения к бд
    def connect_db(self):
        connection = sqlite3.connect('bd.bd')
        return connection

    def register_user(self, login, password):

        try:
            connection = self.connect_db()
            hashed_password = generate_password_hash(password, method='pbkdf2:sha256')
            cursor = connection.cursor()
            cursor.execute("INSERT INTO users (login, password) VALUES (?, ?)", (login, hashed_password))
            connection.commit()
            print("Пользователь успешно зарегистрирован.")
        except Exception as e:
            print(f"Ошибка при регистрации пользователя: {e}")
        finally:
            connection.close()

    def authenticate_user(self, login, password):
        try:
            connection = self.connect_db()
            cursor = connection.cursor()
            cursor.execute("SELECT login, password FROM users WHERE login=?", (login,))
            result = cursor.fetchone()

            if result:
                stored_password = result[1]
                if stored_password and check_password_hash(stored_password, password):

                    return User(login)
                else:
                    print("Неверный пароль.")
            else:
                print("Пользователь не найден.")
        except Exception as e:
            print(f"Ошибка авторизации: {e}")
        finally:
            connection.close()

        return None

    def add_pc_record(self, reg_num, processor_type, disk_size, memory_size):
        connection = self.connect_db()
        cursor = connection.cursor()

        try:
            if not reg_num.isnumeric() or not disk_size.isnumeric():
                raise Exception("Некорректно введенные данные.")


            cursor.execute("SELECT id FROM memory_set WHERE id=?", (memory_size,))
            memory_set_result = cursor.fetchone()

            if memory_set_result:

                cursor.execute("INSERT INTO pc (reg_num, processor_type, disk_size, memory_size) VALUES (?, ?, ?, ?)",
                               (reg_num, processor_type, disk_size, memory_size))
                connection.commit()
                print("Запись успешно добавлена.")
            else:
                print("Неправильный размер памяти.")
        except Exception as e:
            print(f"Ошибка в добавлении записи: {e}")
        finally:
            connection.close()

    # функция удаления записи по ID в таблице pc
    def delete_pc_record(self, pc_id):
        connection = self.connect_db()
        cursor = connection.cursor()

        try:
            cursor.execute("DELETE FROM pc WHERE id=?", (pc_id,))
            connection.commit()
            print("Запись успешно удалена.")
        except Exception as e:
            print(f"Ошибка при удалении записи: {e}")
        finally:
            connection.close()

    # функция удаления записи по ID в таблице memory_set
    def delete_memory_set_record(self, memory_set_id):
        connection = self.connect_db()
        cursor = connection.cursor()

        try:
            if not memory_set_id.isnumeric():
                raise Exception("Некорректно введенные данные.")
            cursor.execute("DELETE FROM memory_set WHERE id=?", (memory_set_id,))
            connection.commit()
            print("Запись успешно удалена.")
        except Exception as e:
            print(f"Ошибка удаления записи: {e}")
        finally:
            connection.close()

    # функция поиска в таблице pc по reg_num
    def search_pc_record(self, reg_num):
        connection = self.connect_db()
        cursor = connection.cursor()

        try:
            cursor.execute("SELECT * FROM pc WHERE reg_num=?", (reg_num,))
            result = cursor.fetchone()

            if result:
                print("Запись найдена:")
                print(result)
            else:
                print("Запись не найдена.")
        except Exception as e:
            print(f"Ошибка при поиске записи: {e}")
        finally:
            connection.close()

    # Функция для отображения всей таблицы "pc" с memory_set num
    def display_pc_table(self, memory_size=None):
        connection = self.connect_db()
        cursor = connection.cursor()

        try:
            if memory_size is None:
                cursor.execute("SELECT pc.id, pc.reg_num, pc.processor_type, pc.disk_size, memory_set.num "
                            "FROM pc JOIN memory_set ON pc.memory_size = memory_set.id")
            else:
                cursor.execute("SELECT pc.id, pc.reg_num, pc.processor_type, pc.disk_size, memory_set.num "
                           "FROM pc JOIN memory_set ON pc.memory_size = memory_set.id "
                           "WHERE memory_set.num = ?", (memory_size,))
            result = cursor.fetchall()

            return result 
        except Exception as e:
            print(f"Ошибка отображения таблицы ПК: {e}")
        finally:
            connection.close()


    # Функция для отображения списка ID memory_set
    def display_memory_set_ids(self, memory_size=None):
        connection = self.connect_db()
        cursor = connection.cursor()

        try:
            if memory_size is None:
                cursor.execute("SELECT id, num FROM memory_set")
            else:
                cursor.execute("SELECT id, num FROM memory_set WHERE num = ?", (memory_size,))

            result = cursor.fetchall()
            return result 

        except Exception as e:
            print(f"Ошибка отображения ID memory_set: {e}")
        finally:
            connection.close()


    # функция добавления записи в memory set
    def add_memory_set_record(self, num):
        connection = self.connect_db()
        cursor = connection.cursor()

        try:
            if not num.isnumeric():
                raise Exception("Неверное число.")
            cursor.execute("INSERT INTO memory_set (num) VALUES (?)", (num,))
            connection.commit()
            print("Запись Memory_set успешно добавлена.")
        except Exception as e:
            print(f"Ошибка при добавлении записи memory_set: {e}")
        finally:
            connection.close()

    # Функция получения данных записи по ID в таблице pc
    def get_pc_record(self, pc_id):
        connection = self.connect_db()
        cursor = connection.cursor()

        try:
            cursor.execute("SELECT * FROM pc WHERE id=?", (pc_id,))
            result = cursor.fetchone()
            return result
        except Exception as e:
            print(f"Ошибка при получении данных записи: {e}")
        finally:
            connection.close()

    # Функция обновления записи в таблице pc
    def edit_pc_record(self, pc_id, reg_num, processor_type, disk_size, memory_size):

        connection = self.connect_db()
        cursor = connection.cursor()

        try:
            cursor.execute("UPDATE pc SET reg_num=?, processor_type=?, disk_size=?, memory_size=? WHERE id=?",
                           (reg_num, processor_type, disk_size, memory_size, pc_id))
            connection.commit()
            print("Запись успешно обновлена.")
        except Exception as e:
            print(f"Ошибка при обновлении записи: {e}")
        finally:
            connection.close()


