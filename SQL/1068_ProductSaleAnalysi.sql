# Write your MySQL query statement below

select Product.product_name  product_name , Sales.year year , Sales.price price
from Sales left join Product
on Sales.product_id = Product.product_id