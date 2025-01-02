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
197. 上升的温度
```
select `id` from `Weather` a join (select `recordDate`,`temperature` from `Weather`) b on a.`recordDate` = Date_ADD(b.`recordDate`,INTERVAL 1 day) where a.`temperature` > b.`temperature`;
#join连接子查询，Date_ADD(b.`recordDate`,INTERVAL 1 day)来比对时间获取b的时间+1天。
```
1661. 每台机器的进程平均运行时间
```
select a.`machine_id`,round(avg(b.`timestamp`-a.`timestamp`),3) as `processing_time` from `Activity` a join `Activity` b on a.`machine_id` = b.`machine_id` and a.`process_id` = b.`process_id` and a.`activity_type`='start' and b.`activity_type`='end' group by a.`machine_id`;
#round(a,b)函数，a为需要处理的数字，b为保留小数位数。 avg(列)函数，计算平均值。
#group by 会先执行，round(avg())后执行，group by相同列的数据不会显示到结果集中，后面可用avg和sum等函数。
```
577. 员工奖金
```
#为null的值，与数字比较会出现UNKOWN，所以要加上`bonus` IS NULL来过滤。
```
1280. 学生们参加各科测试的次数
```
select s1.`student_id`,s1.`student_name`,s2.`subject_name`,COALESCE(count(e.`student_id`),0) AS `attended_exams` from `Students` s1 CROSS JOIN (select * from `Subjects`) s2 LEFT JOIN `Examinations` e ON s2.`subject_name` = e.`subject_name` AND  s1.`student_id` = e.`student_id` group by s1.`student_id`,s2.`subject_name` order by student_id;

1.首先进行CROSS JOIN，将两张表进行笛卡尔积连接，生成所有可能的学生和科目的数目。
#select * from `Students` s1 CROSS JOIN (select * from `Subjects`) s2;
2.进行左连接Examination表，并设置关联条件科目名和学生ID一致。
#select * from `Students` s1 CROSS JOIN (select * from `Subjects`) s2 LEFT JOIN `Examinations` e ON s2.`subject_name` = e.`subject_name` AND  s1.`student_id` = e.`student_id`;
3.查看上述，发现无关联的id则会为空，分组s1.`student_id`,s2.`subject_name`。如果选择e的学生ID，科目名称，则会因为2和6的值为null，含在一个结果集中。
#select * from `Students` s1 CROSS JOIN (select * from `Subjects`) s2 LEFT JOIN `Examinations` e ON s2.`subject_name` = e.`subject_name` AND  s1.`student_id` = e.`student_id` group by s1.`student_id`,s2.`subject_name`;
4.选择对应列，并且对e中的stdent_id计数，利用COALESCE函数设null为0。
select s1.`student_id`,s1.`student_name`,s2.`subject_name`,COALESCE(count(e.`student_id`),0) AS `attended_exams` from `Students` s1 CROSS JOIN (select * from `Subjects`) s2 LEFT JOIN `Examinations` e ON s2.`subject_name` = e.`subject_name` AND  s1.`student_id` = e.`student_id` group by s1.`student_id`,s2.`subject_name`;
5.最后进行排序。
select s1.`student_id`,s1.`student_name`,s2.`subject_name`,COALESCE(count(e.`student_id`),0) AS `attended_exams` from `Students` s1 CROSS JOIN (select * from `Subjects`) s2 LEFT JOIN `Examinations` e ON s2.`subject_name` = e.`subject_name` AND  s1.`student_id` = e.`student_id` group by s1.`student_id`,s2.`subject_name` order by student_id;
```
570. 至少有5名直接下属的经理
```
1.进行分组，并计数managerId，having过滤到countNum需要大于等于5次。获取计数managerId与达到5次的结果集。
#select `managerId`,count(`managerId`) As `countNum` from `Employee` e1 group by `managerId` having `countNum` >= 5
2.将上述的结果集作为子查询，Employee交叉连接子查询，并进行id等于子查询中managerId的过滤
#select `name` from `Employee` e1 CROSS JOIN (select `managerId`,count(`managerId`) As `countNum` from `Employee` e1 group by `managerId` having `countNum` >= 5) e2 where e1.`id` = e2.`managerId`;
```
1934. 确认率
```
1.首先左连接，并进行选择连接条件。获取对应user_id，以及匹配的所有action。
#select s.`user_id`, c.`action` AS `average_rate` from `Signups` s LEFT JOIN `Confirmations` c ON s.`user_id` = c.`user_id`;
2.以user_id进行组合，根据AVG进行计算平均数，count进行小数点保留。
#select s.`user_id`, ROUND(AVG(CASE WHEN c.`action` = "confirmed" THEN 1 WHEN c.`action` = "timeout" THEN 0  ELSE 0 END), 2) AS `confirmation_rate` from `Signups` s LEFT JOIN `Confirmations` c ON s.`user_id` = c.`user_id` group by s.`user_id`;
```