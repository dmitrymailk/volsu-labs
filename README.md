# Итераторы. Обработка исключительных ситуаций

## Задание 1

Согласно варианту из Лаб/р 1 реализовать наполнение класса однонаправленного списка или стека,
реализовать итератор:

### Функции-члены списка:

```
конструктор по умолчанию; деструктор; конструктор копии;
operator=;
возвращение количества элементов;
проверка списка на пустоту;
operator<< – вывод в поток;
operator+= – добавление элемента в конец списка;
operator+= – добавление в конец списка другого списка;
find – поиск значения и возвращение итератора на него;
remove – удаление элемента в позиции, задаваемой итератором;
remove – удаление диапазона элементов, задаваемого двумя итераторами;
cut – вырезание подсписка, задаваемого двумя итераторами;
insert – вставка элемента в позицию, задаваемую итератором;
insert – вставка подсписка в позицию, задаваемую итератором;
divide – расщепление списка на два в позиции, задаваемой итератором.
Функции-члены итератора списка:
конструктор;
operator\* – ссылка на текущий элемент в списке;
operator++ – префиксный и постфиксный;
eol – состояние «конец списка».
Внешние функции (возможно, дружественные):
foreach – применение функции, передаваемой в качестве параметра, к
диапазону значений, задаваемому парой итераторов;
find – поиск значения в диапазоне, задаваемом парой итераторов;
operator==; operator!=;
operator+ – слияние двух списков в третий;
operator<< – вывод в поток;
operator>> – ввод из потока (признак конца ввода – ввод некоторого значения).
```

Для стека реализовать аналогичный функционал, но в соответствии со свойствами стека.

## Задание 2

Продолжение задания 1. Осуществить контроль возникновения ошибок, используя механизм
обработки исключительных ситуаций (В случае возникновения ошибок генерировать и
обрабатывать исключительные ситуации).
Ввода данных организовать из файла. Осуществлять контроль состояния потоков.
При динамическом выделении памяти предусмотреть обработку исключения, возникающего при
нехватке памяти.
