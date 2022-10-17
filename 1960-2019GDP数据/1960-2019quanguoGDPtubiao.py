#取文件内容(先看是行还自然换行)
from audioop import reverse
from ctypes import pointer
from curses import keyname
from turtle import position
from pyecharts.charts import Bar,Timeline
from pyecharts.options import*
from pyecharts.globals import ThemeType
f=open("/Users/hua/1960-2019全球GDP数据.csv","r",encoding="GB2312")
#如果是行那么就readlines函数，否则就read
dact_f=f.readlines()
#关闭文件
f.close()
#查看有没有无效信息，如果有那就删除
dact_f.pop(0)
#将数据转化为字典存储，格式为
dact_dict={}
#{年份:[[国家,gdp],[国家,gdp]....]}
for line in dact_f:
    year=int(line.split(",")[0])#取年份的数据
    country=line.split(",")[1]#取国家名称
    gdp_shuju=float(line.split(",")[2])#取GDP数据
#判断字典里面有没有指定key
    try:
        dact_dict[year].append([country,gdp_shuju])#append函数：追加只能追加一个参数
    except Exception:
        dact_dict[year]=[]
        dact_dict[year].append([country,gdp_shuju])
#print(dact_dict)
#创建时间线对象
timeline=Timeline({"theme":ThemeType.WONDERLAND})
#排序年份
paixu_year_line=sorted(dact_dict.keys())#取得dact_dict.keys函数是取字典的的所有键
print(paixu_year_line)
#取得前8名的国家
for year in paixu_year_line:
    dact_dict[year].sort(key=lambda elemeent:elemeent[1],reverse=True)
    year_dact=dact_dict[year][0:8]
    x_country=[]
    y_gdp=[]
    for country_gdp in year_dact:
        x_country.append(country_gdp[0])#x轴数据
        y_gdp.append(country_gdp[1]/100000000)#y轴数据
#构建柱形图
    bar=Bar()
    #设置bar配置属性
    bar.set_global_opts(
        title_opts=TitleOpts(title=f"{year}年全国GDP前8排名")#设置bar图标的标题
    )
    #反转数据高低
    x_country.reverse()
    y_gdp.reverse()#列表的元素进行反向排序
    bar.add_xaxis(x_country)
    bar.add_yaxis("GDP(亿)",y_gdp,label_opts=LabelOpts(position="right"))#label_opts=LegendOpts(position="right"设置数值显示为右边
#反转x和y轴
    bar.reversal_axis()
    #设置每一年的图标的标题
    timeline.add(bar,str(year))#第一个参数是数据，第二个参数在时间线上的名字(需要str型)
#设置时间线自动播放
timeline.add_schema(
        play_interval=1000,#延时
        is_timeline_show=True,#是否显示
        is_auto_play=True,#是否自动播放
        is_loop_play=False,#是否循环播放
    )
#绘图
timeline.render("1960-2019年GDP前8排名.html")
print("图标以创建") 