﻿**Перегрузка операторов**

Ключевое operator слово объявляет функцию, указывающую, что означает оператор-символ при применении к экземплярам класса. Это дает оператору более одного значения — "перегружает" его. Компилятор различает разные значения оператора, проверяя типы его операндов.

**Синтаксис:**

Тип operator operator-symbol(parameter-list)

**Комментарии**

Функцию большинства встроенных операторов можно переопределить глобально или для отдельных классов. Перегруженные операторы реализуются в виде функции.

Имя перегруженного оператора — operatorx, где x является оператором, как показано в следующей таблице. Например, чтобы перегрузить оператор сложения, необходимо определить функцию с именем operator+. Аналогичным образом, чтобы перегрузить оператор сложения или присваивания, +=определите функцию, называемую оператором+=.

**Переопределяемые операторы**


|**Оператор**|**Имя**|**Тип**|
| :- | :- | :- |
|,|Запятая|Двоичные данные|
|!|Логическое НЕ|Унарный|
|!=|Неравенство|Двоичные данные|
|%|Модуль|Двоичные данные|
|%=|Назначение модуля|Двоичные данные|
|&|Побитовое И|Двоичные данные|
|&|Взятие адреса|Унарный|
|&&|Логическое И|Двоичные данные|
|&=|Назначение побитового И|Двоичные данные|
|( )|Вызов функции|—|
|( )|Оператор приведения|Унарный|
|\*|Умножение|Двоичные данные|
|\*|Разыменование указателя|**Унарный**|
|\*=|Присваивание умножения|Двоичные данные|
|+|Сложение|Двоичные данные|
|+|Унарный плюс|Унарный|
|++|Приращение 1|Унарный|
|+=|Присваивание сложения|Двоичные данные|
|-|Вычитание|Двоичные данные|
|-|Унарное отрицание|Унарный|
|--|Уменьшение 1|Унарный|
|-=|Присваивание вычитания|Двоичные данные|
|->|Выбор члена|Двоичные данные|
|->\*|Выбор указателя на член|Двоичные данные|
|/|Отдел|Двоичные данные|
|/=|Присваивание деления|Двоичные данные|
|<|Меньше чем|Двоичные данные|
|<<|Сдвиг влево|Двоичные данные|
|<<=|Сдвиг влево и присваивание|Двоичные данные|
|<=|Меньше или равно|Двоичные данные|
|=|Назначение|Двоичные данные|
|==|Равенство|Двоичные данные|
|>|Больше|Двоичные данные|
|>=|Больше или равно|Двоичные данные|
|>>|Сдвиг вправо|Двоичные данные|
|>>=|Сдвиг вправо и присваивание|Двоичные данные|
|[ ]|Индекс массива|—|
|^|Исключающее ИЛИ|Двоичные данные|
|^=|Исключающее ИЛИ/присваивание|Двоичные данные|
|||Побитовое ИЛИ|Двоичные данные|
||=|Назначение побитового включающего ИЛИ|Двоичные данные|
||||Логическое ИЛИ|Двоичные данные|
|~|Дополнение до единицы|Унарный|
|delete|Удалить|—|
|new|Оператор new|—|
|операторы преобразования|операторы преобразования|Унарный|

Операторы, перечисленные в следующей таблице, не могут быть перегружены. Таблица содержит символы # препроцессора и ##.

**Непереопределяемые операторы**



|**Оператор**|**Имя**|
| :- | :- |
|**.**|Выбор члена|
|**.\***|Выбор указателя на член|
|**::**|Разрешение области|
|**? :**|Условная логика|
|**#**|Препроцессор: преобразование в строку|
|**##**|Препроцессор: конкатенация|

Хотя перегруженные операторы обычно называются компилятором неявным образом при их появлении в коде, их можно вызывать и явным образом — точно так же, как и любую функцию - член или функцию, не являющуюся членом.

Point pt;

pt.operator+( 3 );  // Call addition operator to add 3 to pt.


Поиск наибольшего общего делителя и кратного (НОД/НОК). Реализовать это достаточно просто за алгоритмом Евклида:

НОД(a, b) = НОД(a, a mod b);
НОК(a, b) = (a * b) / НОД(a, b);

