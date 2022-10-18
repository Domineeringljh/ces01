# excelJs

> ## 前言

> 引入excelJs

````javascript
excelJs=require('excelJs')
````

> 创建==实例对象==

 ````javascript
workbook=new excelJs.Workbook()
 ````

> 引入将要处理的文件（==工作簿对象==）

````javascript
file=workbook.xlsx.readFile(Path)
````

> parse数据 await/then

````javascript
const work=await file
````

> 遍历每一个工作表(sheet是当前工作表对象，id为当前工作表的id)

````javascript
work.eachSheet((sheet,id)=>{})
````

> ## 具体操作

### 1，获取数据，修改数据，插入数据

> sheet对象)

````javascript
sheet.getCell(number|string).value
````

>拿到指定列的数据(数组)

````javascript
sheet.getColumn(number|string).values
````

> 拿到指定行的数据(数组)

````
sheet.getRow(number|string)
````

> 插入数据

````javascript
// n：插入的地方
// data:[]数据，插入一行
sheet.insertRow(n,data)
````



### 2，删除表/添加表

> 根据eachSheet获取到的id来进行删除	(通过实例对象/==工作簿对象==)
>
> 使用实例对象删除那么就必须在创建工作表对象之后

````javascript
workbook.removeWorksheet(id)
````

> 根据(通过实例对象/==工作簿对象==)进行添加
>
> 使用实例对象添加那么就必须在创建工作表对象之后

````
workboox.addWorksheet(name:string)
````

### 3，合并单元格，添加批注，保护单元格，保护表

>合并单元格（合并后两个单元格的数据就一致了）A3:A4 

````
sheet.mergeCells(string|number)
````

````
mergeCells('A1:A2')
````

````javascript
// start row,start column,end row,end column
mergeCells(1,3,)
````

> 添加批注

````
sheet.getCell('A1').note='hello'
````

> 保护单元格

````javascript
// locked :锁
// hidden :隐藏
sheet.getCell('A1').protection = {
  locked: true,
  hidden: true,
};
````

> 保护表

````javascript
await worksheet.protect('the-password', options);
````

> 取消保护

````javascript
worksheet.unprotect();
````

### 4，保存数据

````javascript
workbook.xlsx.writeFile(path).then(function(){})
````

