echo on
item_io < data\book_sales 
avg_price < data\book_sales
add_item < data\add_item
add_item2 < data\add_item
count < data\add
add < data\add 
userforcount < data\add
mysum < data\mysum

for %%i in (for_ex.exe forcount.exe main_only.exe whilecount.exe) do %%i
