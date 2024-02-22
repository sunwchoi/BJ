-- 코드를 입력하세요
SELECT INGREDIENT_TYPE, SUM(TOTAL_ORDER) asTOTAL_ORDER
from icecream_info i
    join first_half f
    on i.flavor = f.flavor
group by ingredient_type
order by sum(total_order)