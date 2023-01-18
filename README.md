  Все задачи выполнены одним человеком
  Идея решения консольного чата состоит в том, что предлагается на выбор номер действия и с клавиатуры выбираем вариант. Программа состоит из трёх файлов заголовков (User.h, Message.h, Methods.h) и четырёх исходных файлов (Chat.cpp, User.cpp, Message.cpp, Methods.cpp).
  В программе присутствуют классы:
1. User содержит данные о пользователе (имя, логин и пароль).
2. Message содержит данные о сообщении (от кого, кому и текст).
3. Шаблонный класс Methods содержит методы: проверки логина, создание нового пользователя, поиск пользователя по логину и паролю, проверки корректности введённого имени, добавление сообщения в динамический массив, проверки наличия сообщений, вывода личных сообщений и вывода общего чата.
4. Два класса исключений LoginExp и NameExp.