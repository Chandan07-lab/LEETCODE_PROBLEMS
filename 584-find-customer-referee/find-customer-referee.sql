# Write your MySQL query statement below
select name from Customer
where referee_id <>2 or referee_id is null
#(second approach) where ifnull(referee_id,-1) <> 2;
#(third approach multiple column or single) where coalesce(referee_id,refereenu,-1)<>2;
