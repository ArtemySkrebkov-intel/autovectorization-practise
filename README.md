# Практическая работа по векторизации в LLVM

Требуется сделать анализ заданнового цикла в форме отчёта:
Шаблон отчёта: template_report.docx

# Порядок выполнения:

1. Определить конфигурацию тестовой платформы. Занести в отчет в секцию "Конфигурация".
2. Создать секцию исследуемый цикл и добавить туда исходный код цикла из вашего варианта
3. Получить LLVM IR без векторизации и раскрутки:
```
clang -O3 -fno-vectorize -fno-unroll-loops -I./loops/vectorizable/ -DINCLUDE_TEST=\"testN.hpp\" test.cpp -emit-llvm -c -o testN.bc
llvm-extract -func=?run@testFunc@@QEAAXXZ test5.bc -o run-fn.bc
llvm-dis run-fn.bc -o run-fn.ll
```
4. Получить LLVM IR без векторизации, с раскруткой:
```
clang -O3 -fno-vectorize -I./loops/vectorizable/ -DINCLUDE_TEST=\"testN.hpp\" test.cpp -emit-llvm -c -o testN.bc
llvm-extract -func=?run@testFunc@@QEAAXXZ testN.bc -o run-fn.bc
llvm-dis run-fn.bc -o run-fn.ll
```
5. Получить LLVM IR с векторизацией, без раскрутки:
```
clang -O3 -fno-vectorize -I./loops/vectorizable/ -DINCLUDE_TEST=\"testN.hpp\" test.cpp -emit-llvm -c -o testN.bc
llvm-extract -func=?run@testFunc@@QEAAXXZ testN.bc -o run-fn.bc
llvm-dis run-fn.bc -o run-fn.ll
```
5. Получить LLVM IR с векторизацией и раскруткой:
```
clang -O3 -fno-vectorize -I./loops/vectorizable/ -DINCLUDE_TEST=\"testN.hpp\" test.cpp -emit-llvm -c -o testN.bc
llvm-extract -func=?run@testFunc@@QEAAXXZ testN.bc -o run-fn.bc
llvm-dis run-fn.bc -o run-fn.ll
```
5. Заполнить соответсвующие таблицы отчёта.
6. Сравнить полученные IR файлы, объяснить различия. Записать выводы в секцию "Анализ LLVM IR"
7. Провести измерения времени исполнения цикла в тех же самых конфигурациях:
```
# Без векторизации и раскрутки
clang -O3 -fno-vectorize -fno-unroll-loops -Rpass=loop-vectorize ./benchmark_app/main.cpp -I ./loops/vectorizable/ -DINCLUDE_TEST=\"testN.hpp\" -o ./benchmark_app.exe
./benchmark_app/benchmark_app.exe

# Без векторизации, с раскруткой
clang -O3 -fno-vectorize -Rpass=loop-vectorize ./benchmark_app/main.cpp -I ./loops/vectorizable/ -DINCLUDE_TEST=\"testN.hpp\" -o ./benchmark_app.exe
./benchmark_app/benchmark_app.exe

# С векторизацией, без раскрутки
clang -O3 -fno-unroll-loops -Rpass=loop-vectorize ./benchmark_app/main.cpp -I ./loops/vectorizable/ -DINCLUDE_TEST=\"testN.hpp\" -o ./benchmark_app.exe
./benchmark_app/benchmark_app.exe

# С векторизацией и раскруткой
clang -O3 -Rpass=loop-vectorize ./benchmark_app/main.cpp -I ./loops/vectorizable/ -DINCLUDE_TEST=\"testN.hpp\" -o ./benchmark_app.exe
./benchmark_app/benchmark_app.exe
```
8. Занести результаты в таблицу
9. Записать выводы в секцию "Анализ времени исполнения"