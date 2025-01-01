目前解决：
1757. 可回收且底质的产品</br>
584.	寻找用户推荐人  
```
or `referee_id` IS NULL
```
595. 大的国家</br>
1148. 文章浏览I  
```
order by `id` ASC
```
1683. 无效的推文  
```
CHAR_LENGTH(`content`) > 15  #CHAR_LENGTH获取字符长度函数
```
1378. 使用唯一标识码替换
```
# left join 左连接，以左边为准。
```
1581. 进店却未进行过交易的顾客
```
select `customer_id`,count(`customer_id`) AS `count_no_trans` from `Visits` v left join `Transactions` t ON v.`visit_id` = t.`visit_id` where t.`transaction_id` IS NULL group by v.`customer_id`;
#on是连接，不会过滤，and `列` IS NULL会将连接的部分转为NULL，where则会过滤。
#count进行计数，group by按照`列`进行分组
```
