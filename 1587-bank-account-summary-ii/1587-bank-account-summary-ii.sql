# Write your MySQL query statement below
select Users.name as name, sum(Transactions.amount ) as balance
from Users inner join Transactions
on Users.account = Transactions.account  

group by name
having balance>10000

# select name,sum(amount) balance
# from Transactions t
# join Users u
# on t.account = u.account
# group by name
# having balance>10000