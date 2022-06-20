#define NDEBUG

#include<Windows.h>
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<cstring>
#include<assert.h>
#include<wchar.h>
#include<tchar.h>
#include<fstream>
#include<cstddef>
#include<vector>
#include<sstream>
#include<stdlib.h>
#include<locale.h>
#include<ctime>
#include<io.h>
#include<shlobj.h>

#define kdown(x) keybd_event(x,0,0,0);
#define kup(x) keybd_event(x,0,KEYEVENTF_KEYUP,0);
#define mdown mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
#define mup mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
#define mrdown mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
#define mrup mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
#define S(x) Sleep(x);
#define UWnd(x) SetWindowPos(x,NULL,0,0,0,0,1);
#define QWnd SetWindowPos(Qwd,NULL,0,0,0,0,1);
#define r_s Sleep(rand()%7)

using namespace std;

#define OUTDATA
typedef unsigned int QInfType;

inline void mgo(POINT P) {
	SetCursorPos(P.x, P.y);
}
float getSysVersion();	//windows-version(such as windows 10.0)
void throwQFile();
void QWrite();
char* getCBoard();
void writeCBoard();
BOOL StringToClipBoard(char* srcString);
HWND qHWND();
void getinf();
void allcat();
void prefun();
void qsend(char* ch);
void stick();
void ent();
void tdata();
void sget();
void cat();
void jielong(int);
void cleanCBoard();
void command();
bool findsl(char* qg);
void findpic();
void findpic2();
void pre1();
void pre2();
int CopyFileToClipboard(char szFileName[]="C:\\desktop.2.0\\QQrob\\pic\\yydz\\F817606EDF08FAE6BF73268EBBAA6038.jpg");
const char* mappp[] = {"function#1 getSysVersion", "function#2 throwQFile", "function#3 *", "function#4 *", "function#5 *", "function#6 *", "function#7 *", "function#8 *",
                       "function#9 *", "function#10 *", "function#11 *", "function#12 *", "function#13 *", "function#14 *", "function#15 *", "function#16 *", "function#17 *"
                      };
const HWND Qwd = (HWND)0x3021a;
const char* name = "Minecraft Lepton Sever （几乎不含mc元素）";
POINT Qset;
LPPOINT pQset = &Qset;
HWND Qwnd;
const char* fname = "C:\\Users\\21983\\Desktop\\QQrob\\inf.txt";
const char* xzw[20] = {"不推嘉然小姐十年了。\n\n她的名气和出场费都一涨再涨，我原地踏步的工资买不上专辑也打不起榜。终于年前被公司安排下岗，找工作时我才在路边广告发现初代工具人已经当上了厂长。\n\n时间太久，一切都变了。\n\n到处投简历的时候我想起了一名人上人的预言：“这些人只配在下水道里度过相对比较失败的人生。”\n\n像是一条跳过龙门的锦鲤，金鳞被羽耀武扬威地站在门沿上，对其他还在跳的鲤鱼说：\n“你不行！”\n我当时很想反驳，可他说中了。\n我知道我确实不行。我之所以跳了跳，只是为了看下自己能跳成什么样罢了。\n其实每条鲤鱼的龙门都不是一样高的。\n我见过龙门在水下的鲤鱼。看起来是鱼，其实生而为龙。\n也有的生而为鱼肉。\n也见过好运的鲤鱼，门被各种大手摁到河里了。\n我也期待过好运，只是没来而已。\n说起来这就是人性吧。我不讨厌天道酬勤，但是讨厌别人的好运——只是因为我没有好运罢了。\n我也有亲人和宠物会生病；我眼神也挺纯真啊。\n\n讨厌嘉然小姐十年了\n。讨厌的更是越来越深的无力感。\n身在泥潭的人是没力气冲锋的吧。\n三流的人生只会让上等人不屑一顾吧。\n我坐井观天，天穹星海依然耀眼。\n可我爬不出井底。\n那我就不再看星星了。世界那么大，但没我的份。\n\n忘记嘉然小姐十年了。\n可路上看见街边的大荧幕在放A-soul的新年节目，我还是楞在那里了。\n我没有近视，但总觉得眼睛影影绰绰，雾气来自多年以前。这\n个广告位非常贵。真的再也不是小v了啊。\n抖友还在惦记他们的鸭子。\n晚晚仍然只有蓬蓬裙，100首歌竟然还欠着，被粉头小团体以4%年化复利计在小本子了。\n想起她首播时玩2077下饭下得轰轰烈烈，我一边发“粉丝牌改成晚饭人吧”“和嘉然珈乐凑加碗饭”“和乃琳凑来碗饭”一边忍住刷“和贝拉组拉碗饭”的冲动。\nsolo依然拉跨，参团照旧神C。\n贝拉总是六边形战士，乃琳养了成吨的gachi，珈乐还是那个硬壳软妹。\n嘉然小姐依然卖萌摁混。\n什么都没变，是我没跟上她们。\n城里烟火幢幢，灯光下的人热情相拥，阴影里的人压下悸动。\n\n最亮的地方嘉然小姐浅笑起舞，光影从她袖间散落，像是雨天花伞轻旋，摇曳间洒下泪色的流珠。\n忽然眼睛有点模糊。\n我小声说：\n“新年好啊，嘉然小姐。”\n\n不爱嘉然小姐十年了。\n\n十年里，爱过的每个人都像她。",
                       R"(什么是幸运？在遇见嘉然前我每次都会犹豫地给出不同的答案，在遇见嘉然后就有了标准答案。
遇到嘉然，就是此生最大的幸运了。
嘉然是秋天，是光源，是珍馐，是爱情，是捕获我躁动心脏的势阱，是造物主抽选人间所有美好摹刻的恶作剧。她的容颜有星辰的潋滟，她的发丝有江离的清香。她像病毒感染了我的一切，却又像天使治愈了我的一切。她浅笑，她轻唱，她眼里有光，她穿着蠢萌的孕妇装。
我已经是一个被生活中细微繁琐而又悄然堆积的失望磨平了棱角，习惯了退而求其次的人。即使不能拥抱，只要接近就好了；即使不能拯救，只要敷衍就好了；我知道朦胧的美好与清澈的苦楚，知道恋慕的准则与自贱的界限。我深谙一个管人观众的规范，可不要想嘉然的条款我一刻都做不到。泥人说爱上嘉然是灵魂的恶堕，可在爱上嘉然前我甚至从没感觉到灵魂为何物。蚂蚁尚且会追寻糖分的踪迹，那我对嘉然的迷恋怎么就是一出自陶自醉的荒诞闹剧呢？
我过去常常反思我自己到底是什么角色，我会回答自己，一个尼特。太失败了。现在我会说，一个遇见了嘉然的尼特。太幸运了。我光是躺在床上，默念嘉然的名字，眉间被无尽的挫折碾出的沟壑都会变得柔和起来，觉得这人间全都是美好的事，就像嘉然的存在一样。

我知道我与嘉然终将分别，像一只流浪猫一样在度过寒冬后悄悄离开有她的世界，可有这段短暂的守望就已经足够。如同是在伊豆遇见盛装的舞女，在湄公河遇见羞涩的情人，即使知道分别是必然的结束，但来之不易的陪伴已经成为足以回味一生的幸运。嘉然，嘉然，嘉然——我的生命之光，欲念之火；我的罪恶，我的，灵魂。)",
                       R"(在上主天主创造天地时，地上还没有灌木，田间也没有生出蔬菜，因为上主天主还没有使雨降在地上，也没有人耕种土，有从地下涌出的水浸润所有地面。上主天主用地上的灰土形成了人，在他鼻孔内吹了一口生气，人就成了一个萌萌的生物。上主天主以他的伟力在北方创造了原野，让萌萌人在冰原上生息。在萌萌人败坏之后，上主要给萌萌人以严惩，遂裂解了他们的国，把他们的土沉入冰海。萌萌人是灰土所结，上岸尽皆被冰水浸透成了泥人，于是剩下的土就归泥人所有；还有萌萌人爱上了凫水的乐趣，于是自称乐子人，他们常年游弋在冰海，取笑落入冰海手忙脚乱的泥人。

泥人嘲笑乐子人常年泡在冰海里，而乐子人却知道上主从未赦免他们的罪——泥人新爬上的地也非原初的乐土，而是濒临破解的巨块浮冰。乐子人潜入水底，看到泥人足下的巨冰被裂隙纵贯。有乐子人向泥人言及他们国的危机，却被泥人认为是嫉妒他们在岸的安生，要拉他们下水；有睿智的泥人也看到冰下的隙，劝泥国的人一起修补，亦被其余泥人塞上口球踢下冰海。
泥人以打钱为据划分疆土。打钱多者说话响者站在巨冰之心，有人以其马首是瞻，把最外圈的泥人挤下溶解缩小的浮冰，乐子人称之为提纯。有落水的泥人新寻了冰山上岸，或者亦爱上游水，泥人称之为恶堕。泥人自认继承了萌萌人的正统，从不看冰下的裂隙，认为在岸上呆一刻算一刻；乐子人则游到岸边也不轻易上岸，愿意跳水多甚于愿意落水。

上主垂怜泥人与乐子人，于是往冰海里升起新的土，乐子人和泥人皆视于新生的岸。提纯后的泥人非常恐惧，呼其为资本的陷阱，转身不看，避而不谈。众多乐子人游了一圈暂未发现沉没的迹象，于是约好如有危险再次跳海后上岸。
次日有乐子人想要逗弄众人，于是谎称发现新土要沉了，乐子人尽皆匆忙跳海。对岸偷看的泥人看到这一幕才突然想起，乐子人和泥人原本都是萌萌人罢了。他悄悄下了水，游到对岸的乐子人边。乐子人看到他不想让他上岸，说:“ybb?”
泥人说:“有冰。”说完把随身扛着的一块冰切了一块扔上来，乐子人一看大惊失色。
这个游过来的泥人身上背着的冰块上横竖写着密密麻麻，歪歪扭扭的“杏2ndlive”几个大字。)",
                       R"(我好想做嘉然小姐的狗啊。
可是嘉然小姐说她喜欢的是猫，我哭了。
我知道既不是狗也不是猫的我为什么要哭的。因为我其实是一只老鼠。
我从没奢望嘉然小姐能喜欢自己。我明白的，所有人都喜欢理解余裕上手天才打钱的萌萌的狗狗或者猫猫，没有人会喜欢阴湿带病的老鼠。
但我还是问了嘉然小姐:“我能不能做你的狗？”
我知道我是注定做不了狗的。但如果她喜欢狗，我就可以一直在身边看着她了，哪怕她怀里抱着的永远都是狗。
可是她说喜欢的是猫。
她现在还在看着我，还在逗我开心，是因为猫还没有出现，只有我这老鼠每天蹑手蹑脚地从洞里爬出来，远远地和她对视。
等她喜欢的猫来了的时候，我就该重新滚回我的洞了吧。
但我还是好喜欢她，她能在我还在她身边的时候多看我几眼吗？
嘉然小姐说接下来的每个圣诞夜都要和大家一起过。我不知道大家指哪些人。好希望这个集合能够对我做一次胞吞。

猫猫还在害怕嘉然小姐。
我会去把她爱的猫猫引来的。
我知道稍有不慎，我就会葬身猫口。
那时候嘉然小姐大概会把我的身体好好地装起来扔到门外吧。
那我就成了一包鼠条，嘻嘻。
我希望她能把我扔得近一点，因为我还是好喜欢她。会一直喜欢下去的。

我的灵魂透过窗户向里面看去，挂着的铃铛在轻轻鸣响，嘉然小姐慵懒地靠在沙发上，表演得非常温顺的橘猫坐在她的肩膀。壁炉的火光照在她的脸庞，我冻僵的心脏在风里微微发烫。
)",
                       R"(看了今晚直播始终有些奇妙的感觉，想要写点东西祝嘉然小姐生日快乐。但是犯病自然是不适合的，表白又有点炒作过度。好像写篇骈文把这几个月的嘉然歌功颂德一番再展望美好未来比较适合，可除了炫技以外又没什么意义。
但我觉得写不出好的，就可以选择不写。

而嘉然小姐是不能“不写”的。团队的责任也好，粉丝的期待也罢，她站在了这个位置，就不得不承担这一切。
而且她也不懂她的观众觉得什么是“好”。嘉心糖的喜好其实连嘉心糖自己也不能确定。对整个圈子甚至整个互联网也排得上号的复杂团体来说，意见不合是常态，拱火乱战是习惯。本来绝无成为一个集体的可能，只是因缘巧合下成了名为“嘉心糖”的群体。
嘉然就是这个因缘。

嘉心糖自然都是喜欢嘉然的，但对这个因缘难称温柔。可能只有这么一群不够温柔的观众，心里是为了主播好，却傲娇又固执，让她在直播间被批评得偷偷抹泪几次，强颜欢笑时又说她不够真实。

一般的主播早就厌倦这群粉丝了吧。
但她说她会在手帐里记下开心的事，一大半都是嘉心糖。
她说不许说嘉心糖坏话，都是很厉害的人。
她会不好意思地说：“你们今天怎么那么会说话。”
她重复了很多次：“每年的生日都要和大家一起过。”

我是一个不喜欢过生日的人，很长时间都不理解生日的意义。
是的，就像我很长时间不理解虚拟偶像的意义。
更何况虚拟角色的生日，本就是一个缘由复杂的命题。
原来是“陪大家一起过”。

可观测的宇宙有900多亿光年，宇宙的寿命达到137亿岁，我们都只是银河系某个旋臂上渺小星辰里奇迹般诞生的生命，能够恰好在这个时间相遇不能不说幸运。
我一直以冰冷的解构视角理解世界，在我的逻辑里偶像是用人设扮演交换真情实感，用贩卖梦想换取现实财产。
原来应该是以陪伴交换陪伴。

生日从来不应该是一个人过的，它是一种有点笨拙的陪伴宣言：我在你身边。
已经过了12点了，但还是再说一句，生日快乐，嘉然小姐。希望不那么温柔的嘉心糖，都能够长久陪在你的身边。
)",R"(嘉然想要一件漂亮的衣服
和yhm一样靓丽的裙子
鼠鼠们犯了难
要是有天国的锦缎该多好啊
以金银色的光线编织
还有湛蓝的夜色与洁白的昼光
以及黎明和黄昏错综的光芒
要是然然得了这锦缎
她该有多开心啊
但是啊，鼠鼠们，如此贫穷，除了梦一无所有
于是鼠鼠们每个人拿出自己的梦
凑了一件可爱的衣裳
然然穿着很合身
有了这件衣服，然然终于得了猫猫的喜爱
越来越多的猫猫依偎在然然的怀里
鼠鼠们再不敢靠近嘉然小姐了
只敢偷偷地从洞里探出脑袋
望着她，望着她
偶有发了病的鼠鼠冲出来
转瞬便葬身猫口
终于有一天
嘉然得了天国的锦缎
身边的猫猫也嫌弃鼠鼠的衣服太过寒碜
然然穿上新衣服
华丽动人，连yhm都要心生嫉妒
是时候丢掉旧衣服了
然然回想起
她与鼠鼠一起度过的时光
她陪伴鼠鼠唱过的歌曲
她为鼠鼠哭泣过的夜
又于心不忍了
于是她整齐地把衣服垫在枕头下
与此同时
阴暗的洞里，一只鼠鼠悄声说道
“轻一点啊，因为你枕着我的梦”)", R"(我想不通猫是怎么中毒的，他们口中的猫中毒是什么。直到今天我终于明白，不是猫中毒了，而是我这只鼠鼠对猫中毒了。
    每天我都要看四遍这只猫，早中晚各一遍，梦里一遍。她习惯去楼下的草地上晒太阳，日复一日。听其他的鼠鼠说，她因为有很多人喂食，所以不会去抓鼠鼠，在她面前我们是安全的。又有鼠鼠说，她是极其危险的，因为他们曾看过她抓住一只鼠鼠反复捉弄挑逗，直至那只鼠鼠承受不住跳进了河里。风言风语太多了，我因此起了兴趣，决定靠近去了解。
    我最开始在她经常经过的草丛里蹲着，藏在草里面就能在看见她的同时不被发现。她的四只脚毛茸茸的，没有爪子，似乎被剪掉了。我看到的时候松了一口气，如果我被她发现，起码不会被爪子刺穿。知道自己没有生命危险后，我更进一步，在楼梯背后蹲着，观察她进餐。好人给予的食物总是丰富充足的，她进餐时也不必像我们一样会狼吞虎咽，而是优雅的。那种优雅，抱歉我不知道怎么形容，我只能告诉你，那是我见过的最享受的进食。至此，我已经确定了，这只猫只不过是一只娇生惯养的无害猫。
    不知道什么时候起，也许是第一次观察起，我已经养成了习惯，就是每天在她经过的草丛蹲着。闻着残留的猫香，我总能愉悦一整天。直到有一天，我被她抓住了。她没有尝试用爪子刺穿我，甚至连爪子都没有露出来。仅仅是追逐，这种追逐对她来说是儿戏，但对于好几天没吃到食物的我却是致命的。我被赶到了角落，已经无法再奔跑。盯着面前的猫脸，我的脚在抽搐，身体在发抖，脸膀胱都无法抑制住。最后我昏迷了，我昏迷在一片黄色液体中，与骚臭味对立着的是空中悬浮着的猫香。我想，我死去的场景是如此的戏剧，一生所有的俗与高高在上的雅混杂在一起，此刻却如此和谐。
    我在萍伦区心鼠医院醒来的，这里有很多像我一样的病鼠，我以前也听说过，他们是得了一种叫猫中毒的病。以前我不懂这是什么，现在懂了。医生说我得了臆想症，被发现时躺在下水道里。在这里治疗的鼠鼠很多，每天的药就是定时看些视频，睡前听些音乐。缓解是能缓解的，但这种病还无法根治。但也无所谓了，我不在乎，甚至庆幸。

我很喜欢鼠志摩的一首诗:

“我不知道风

是在哪一个方向吹——

 我是在梦中，在梦的轻波里依洄。

我不知道风

是在哪一个方向吹——

我是在梦中，她的温存，我的迷醉。”
现在半夜，我也时时想起。不管风往哪个方向吹，唯一不变的，是我心底喜欢的你。)", R"(我有一个朋友。
朋友是个好人。
起码他表白过的女孩子都这么说。
然后补一句：“但是我们不合适。”
朋友觉得不对。怎么会有和好人不合适的人呢？她觉得自己和坏人合适？
“她不是正常女人。还好没有答应我，不然我肯定会被她玩得很惨的。”
朋友这么说。

朋友确实是个好人，我是这么觉得。起码他的底线比我多。
但我觉得他的脑回路里有一堆二极管。
那也挺好的，二极管比BJT和FET都好懂。
//BJT：晶体三极管    FET：场效应管

朋友喜欢咸粽。他端午的时候要和宿舍一整层吃甜粽的人辩论，直到对方承认正常人爱吃咸粽。
所以我每年端午都回家。
朋友喜欢古典，我从不在他面前谈流行。
朋友F闪现。
朋友……
我其实有些羡慕朋友。能保持这样这么多年的人要么人生一帆风顺，要么就是做着梦的堂吉诃德了。

有天朋友神秘兮兮地问我：“中秋你准备买水果馅月饼还是肉馅？”
我赶紧答：“我中秋回家，随我妈买啥。”
他说：“你这样节日总是回家不正常！学生要有学生的觉悟……”

年末的时候我开始高强度冲浪。那段时间我很喜欢嘉然小姐，评论区各种观众团建狂欢群魔乱舞，我也在那里拟态各种角色。
直到我看见我关注列表里朋友的账号也关注了嘉然小姐，心里忍不住咯噔一下。

我在评论区翻着，想看看朋友有没有发表什么突破性成果。
果然很早的时候他就在嘉然小姐的动态下发表了第一条评论：
“正常人谁看这个V啊?”

我很久之后才翻到他的第二条评论。

“怎么没有正常评论？”)", "矮矮的少女蹲在墙角，刚刚才脱下动捕服的她汗水还没有消失，穿着单薄也并未觉得寒冷，空调让室内的空气显得格外干燥，巧克力放在嘴中一点点的抿开，不断地划动着手机，带着急切而又紧张的心情想要看看今天直播的反馈。嗯～巧克力在少女的嘴里慢慢融化，苦涩中的香味在嘴里弥漫，少女如同慵懒的猫一样发出了舒服的声音。今天的直播数据比之前好多啊，今天不少人给然然上船，但是他们是为了明信片还是喜欢然然呢？这种事情真的是很难想啊，嘉心糖们都好奇怪，他们好像不是很喜欢然然，明明为了开播做了那么多的努力，唱歌跳舞都要学习可是无论如何也做不到像是珈乐贝拉那么厉害啊，学习怎么样才能在各种奇奇怪怪的弹幕里面做出正确的回复，可是那些弹幕里面的很多内容我真的不知道啊。每天训练的时候都要把手机上交，休息的时候已经训练的很累了，但是那些来自嘉心糖的善意也不能忽视吧......时间在少女的思索中流走了身上的汗水留下的只剩下了一点寒意，把伸开的腿蜷了起来，左手搭在双膝上面，下巴抵着手背头轻轻地歪着，被汗水沾染的头发一绺一绺的垂着却都懒得理会。右手还在划动着屏幕，看看自己的二创。嗯唔~~他们怎么把然然的头到处P啊，明明是很可爱的女孩子的，这么喜欢恶作剧的话能讨得到女孩子的开心吗？这次的直播还好吧？嘉心糖们怎么老是说那些铁棍电棍啊，明明都是谣言，要是真的打了的话，然然早就跑了。巧克力没有了，站起身来，不管脏不脏，拍一拍总归是好的。这是第三首歌了吧，乃琳今天怎么唱了三首？先不管那些了，时间到了可以回去了。一跳一跳地跑到了正在脱动捕服的乃琳面前。“乃琳~我们去吃夜宵吧，好不好嘛。”“你又想吃那些高热量的食物吧，我可不想变胖。”“好吧”沉沉的应到“好了，都半夜了我们赶快回去洗个澡睡觉啦。”“那我先洗。”“好好好。”乃琳缓缓地把她拉过来，轻轻地抱着她，仗着身高胡作非为。“大的要来了！大的要来了！”尝试性的挣脱并没有什么结果，只能反过来像一只八爪鱼一样缠在她身上。“别闹。”打掉那双放在不该放的地方的手，“向晚是A的话，那你...”“哼，我先去打车了，你穿好衣服，我在外面等你”趁大的没反应过来，小的已经跑出了门外。", R"(我不明白啊……我不明白！
v8人说的 我一个字都不明白啊！
v8人所说的东西，我不明白重点在哪里！
我不明白，对我来说不明白啊！
“懂得都懂”这种废话哪里帅了？
都懂了的话，还轮得到你在这里说吗？
“乐子人”是什么人？
连点提示都没有我根本不明白啊！
“开爱丽丝我??了你”开是什么意思，为什么要杀人啊？
不要因为这种小事就去干犯罪的事啊！
再说了破防到底是什么？
抗压差？ 所以说抗压到底是什么啊？
说话含含糊糊为什么会觉得帅气呢？
“显得自己懂很多”？
这算什么 谁看的出来你懂啥啊？
能好好说明的人才帅啊！
这样才出色啊！
用一堆emoji谐音到底哪里厉害了？
这样的不就只是又怂又想装吗？
就算很麻烦，也要努力把事情讲清楚的人才帅啊！
用缩写给我差不多一点啊！
缩写都比汉字多了不是只是更加的理解困难吗？
不管是英语还是什么，起码给我统一成一种语言再缩写啊！
我根本记不住啊！
别写成??读作反串了啊！
别写成????读作化身恶魔啊！
别写成??读作日本啊！
mmr、x皇、x宝、三字母、991什么的，
又不常用重复率又高也不是违禁词谁猜的到啊！
不好好告诉我内容，我根本不懂啊！
要告诉我的话就好好告诉我啊！
什么怕中文、天空之城、贫穷sc、相信yagoo，
只不过是稍微看了吧里的截图，
就不要装作你很懂似的啊你那半吊子的说明我一丁点也不明白啊！
不要引用狗妈和b站观众们的话啊！
就算你用这些不认识的人说的话到底想要表达什么我根本不明白啊！
用自己的话说啊！
算我求你了，说点我能明白的话吧！
我不明白！我不明白！我不明白！我不明白！
我不懂啊！
v8人至今为止所说的一切，我半点也不明白啊！
??????)", R"(你知道雪为什么是白色的吗？那是因为它忘记了自己的颜色。
你知道嘉然小姐为什么这样可爱吗？那是因为她是上天所赐予我的礼物。
是嘉然小姐改变了我！是嘉然小姐的笑容拯救了我！
所以，如果是为了保护嘉然小姐，就算死，我也无可畏惧，因为我，最喜欢嘉然小姐了。
如果能够允许的话，
千山万水，你能陪我一起看吗？
千言万语，你能陪我一起诉说吗？
千千万万个日月，你能陪我一起度过吗？
当我看到了嘉然小姐的瞬间，我就明白，昨天很喜欢你，今天也很喜欢你，明天也会喜欢你，永远都会喜欢你。
就算灯塔已经失去了光明…… 就算前方充满荆棘……
但是，只要嘉然小姐的笑容仍在，就一定能将人们再次导向此方。
春去秋来，寒来暑往。
嘉然小姐的笑容如同春天的雨，轻盈温婉
嘉然小姐的料理如同夏天的火，明亮灼热
嘉然小姐的声音如同秋天的风，温柔甜美
嘉然小姐的睡容如同冬天的雪，洁白无瑕
嘉然小姐起床了,好耶！
嘉然小姐直播了,好耶！
嘉然小姐发动态了,好耶！
嘉然小姐做饭了,好耶！
嘉然小姐高兴了,好耶！
嘉然小姐生气了,好耶！
嘉然小姐害羞了,好耶！
嘉然小姐上线了,好耶！
嘉然小姐睡觉了,好耶！)", "我真的想嘉然想得要发疯了。我躺在床上会想嘉然，我洗澡会想嘉然，我出门会想嘉然，我走路会想嘉然，我坐车会想嘉然，我工作会想嘉然，我玩手机会想嘉然，我盯着路边的一米吧看,我盯着马路对面的一米吧看,我盯着地铁里的一米吧看，我盯着网上的嘉然看，我盯着朋友圈别人合照里的嘉然看，我每时每刻眼睛都直直地盯着嘉然看，像一台雷达一样扫视经过我身边的每一个嘉然，我真的觉得自己像中邪了一样，我对嘉然的念想似乎都是病态的了，我好孤独啊!真的好孤独啊!这世界上那么多嘉然为什么没有一个是属于我的。你知道吗?每到深夜，我的舌头滚烫滚烫，我发病了我要疯狂吃嘉然，我要狠狠吃嘉然，我的嘴巴受不了了。",
 R"(嘉然小姐的住宅边今天来了个新邻居。
 新邻居一来，周围的猫猫便一窝蜂依偎在她的旁边，舔舐着她的手指，喵喵地乖叫着。这是嘉然小姐从来没有受到过的待遇。
 偌大的城市，只有嘉然小姐来时没有被猫猫们夹道欢迎。无论嘉然小姐努力多少次，跳多少支舞给猫猫们看，唱多少首歌给猫猫们听，猫猫们都置之不理，只长瞥一眼，便窜往别的住宅，给它们的主人献媚去了。
 只有我这样的老鼠，是嘉然小姐忠实的观众。半年过去了，当年立下的“不惜葬身猫口，也要把可爱的猫猫引来”的誓言，除了这一堆嘉然小姐住宅的下水道里住满的老鼠以外，我什么都没能引来。
 她每天都在努力的练歌练舞。我想不明白，嘉然小姐的歌舞，可以说得上是全城第一，为什么就不受猫猫们的喜欢呢？
 嘉然小姐，大概还是喜欢猫猫的吧。嘉然小姐表面上对我们这些老鼠的温柔，会不会是出于一种投鼠忌器的担忧呢。
 于是我问嘉然小姐，问她是不是还是喜欢猫。
 嘉然小姐用她洁白的手，摸了摸我们这群佝偻丑态的老鼠的头。她说，有我们，就足够了。
 可是嘉然小姐仍然把目光盯向窗外的猫猫。那种渴望感，哀伤感，是对我们这些老鼠从来没有表现出的。
 凝视着嘉然小姐的目光，我泪流如注。
 为什么我不是一只猫呢。
 为什么我生来就是一只老鼠呢。
 对不起，不能像猫猫一样可爱，对不起。
 对不起，一直以来都住在你家的下水道里，对不起。
 对不起，教了你一些奇奇怪怪的老鼠话，让猫猫对你更加疏远了，对不起。
 对不起，我没能履行葬身猫口的誓言，没能引来你喜欢的猫猫，对不起。

 嘉然小姐，请原谅我的自私。你心爱的猫猫，我不会再去引了。我只想，以后永远都与你在一起)"          ,
 R"(你说你喜欢猫，可我只是长耳朵白老鼠，纵使扮作妖娆模样，也没有那自魅的身姿。我总是在人群里兜兜转转，喜欢每一个人，为她们应声喝彩，可我只是一只白老鼠，她们听不见我的嘶叫，我也听不懂她们的话语，能做的只有随声附和。又总会被他人发现，“死老鼠，滚出去！”，他们总会把所有不幸怪在我们头上，极度排斥我们，我只能继续兜兜转转，四处碰墙。
 你说你喜欢猫，却又不讨厌老鼠，学着我们在殿堂上吱吱喳喳，为我起舞。在这里没有白鹿的温顺，也没有青鸾的高傲，有的只是快乐的老鼠，它们找到了嘉)",
 R"(我一直都是嘉然小姐的猫啊
 明明我花纹很乱，嘉然却喜欢摸
 明明我有点胖，嘉然却经常抱
 明明我吃的不多，食盆却总是满满的
 要问为什么呢？可能是我比较聪明吧
 刚到嘉然家里的第一天，就进了厨房
 咬死了米袋里最大的那只老鼠。
 嘉然看起来很生气地说：坏猫咪
 今天嘉然买了新的逗猫棒，伸进了我的小窝
 一路追逐，无意间路过了厨房
 其实我知道的，我从没有咬死过老鼠
 我咬死的，是和其他老鼠一起吱吱叫的自己
 没办法啊，嘉然小姐喜欢的是猫啊，那我是猫不是很合理吗
 我一直都是嘉然小姐的猫啊)"
 ,R"(我本以为我的一生是无聊且平凡的
 没想到一个名叫嘉然的女孩子
 突然闯进了我的生活
 嘉映我心，然情而至！
 要是这么可爱的女孩子能和我在一起
 我此生便无憾了！
 和她一起在海边拾贝壳 看她淘气的身影
 和她一起在枫林赏枫叶 看她在叶中舞蹈
 和她一起在山顶看流星 看她幸福的微笑
 可惜啊 一切都是梦！
 她是个偶像 要站在舞台上闪闪发光
 我只是普通的观众 只能为她默默打call
 那些事我无法和她一起完成啊
 哦不 我连她也从未拥有啊。。
 果然 我的人生一辈子都是无聊且平凡的吧)"       ,R"(A骚至，8友一，
 泥哥死，嘉然出！
 她如圣女般到来，
 不畏惧众人的鄙夷
 在谩骂声中独自前行。
 世人皆醉她独醒，
 世人皆浊她独清。
 于是一次又一次，
 越来越多的人被她所感化，
 终于开始意识到自己的愚蠢
 这一刻，我才知道，
 长风破浪会有时，
 直挂云帆济沧海！
 越是冰天雪地，
 越是在冷冽的黑暗中绽放，
 这一刻，我才知道，
 苦尽甘来春满园，
 姹紫嫣红别样情！
 倘若有人问起嘉然，
 我一定放声高歌，
 高歌伟大的嘉然！
 寄意DD荃不察，
 我以我血荐嘉然！)"    ,R"(我在下水道
 捡到一块心形的石头
 十二月十二日
 我来到到了离她几米远的水面
 如果运气好
 她会问我手里面拿着的是什么
 那时，我便会告诉她
 我想给她看看的天空星光

 阳光
 沙滩
 大海
 我把他们倒进了酒杯里
 调出可乐一样的气泡

 奶茶
 蝴蝶结
 那是波提切利的素描
 光线穿透过树荫
 她也用指尖穿过头发
 她便是那诞生的颜料

 我趴着看她
 我觉得好难过
 我始终认为
 坐在那儿的应该是两个人

 她跟我说话了
 但是我知道我的酒杯也将摔碎掉
 我精心为她调制的饮料
 洒在了《茶花女》第二十一章
 气泡也开始蒸发了
 飘到了一览无云的天空上

 我笑着
 跑入水渠
 逆流的人群只是我的缩影
 我知道
 有些东西会遗忘
 像身边逆流的人群
 而我笑着跑向
 那水渠
 带着我的石头
 一起沉入 沉入到魅蓝色的水底)",R"(“我想我爱上嘉然小姐了” 他没有反应，继续忙着手上的事。 凛冬的寒风杂糅着冰雪无情地拍打在城堡房檐的缝隙上，我哆嗦一阵抖下还未来得及融化的雪，侧过身用另一半躯体堵住那道缝。“我忘不了她，从第一眼看到嘉然小姐起才明白，内心那垒地极高的墙在她面前是如此不堪一击。” 他只是顿了顿，轻叹了一口，依旧不予理会。“我都快要疯了，每当进入良夜，闭上眼便能看到嘉然小姐优美的舞姿、耳边回响着她那干净的笑声，我想去抓住她的手，但睁眼却只有阴暗长着青苔的墙和潮湿泛着腥臭的浑水。” 他侧过身体，眯着眼看了看我那冻的发紫的后背，却没有开口。 风越来越大，像是再帮他作回应。 我颤抖的身子低头看着房檐下面，她那小脸被壁炉火光辉映的分外精致。 心乱如麻，原本计划好的生活全被眼下的女人打乱。 心乱如麻，现在满脑子想的都是下次会在什么时候和嘉然小姐见面。 心乱如麻，甚至会忘记自己的身份，以为自己是一位签下守护公主契约中世纪的骑士，一名对待女性彬彬有礼，风度翩翩的绅士。“该死的风！我打算就在翌日的清晨，将自己的思绪传达给嘉然小姐。” 大雪一夜未停，翌日晨光洒进城堡里，管家命令仆从堵住了房檐上的鼠洞。 ......“她...喜欢猫”这是他对我说的最后一句话。“那我就下辈子做嘉然小姐的猫”)"
 ,R"(嘉然さんのワンちゃんになりたくて仕方がありません。
 　でも嘉然さんは猫が好きだって仰っていましたから、私は泣きました。
 　犬でも猫でもない私がなぜ泣いたのかはわかっています。本当は私、鼠なんですから。
 　嘉然さんに好いてほしいなんて望む度胸など私にはありません。誰だって理解余裕上手天才でお財布にもなれる萌え萌えワンちゃんと猫ちゃんが好きなんでしょうし、陰湿で病弱な鼠のことなんて好きな人は一人もいませんよな。
 　そんな私でも嘉然さんにこう問いかけてみました。「貴女の犬にはなれないのでしょうか」と。
 　犬には決してなれないという事は承知の上です。もしも彼女は犬が好きだったら、隣でずっと見守って差し上げられるんでしょうね。たとえ彼女が懐に抱いてるのはずっと犬であったとしても。
 　しかし彼女は「猫が好き」だって仰っていました。
 　彼女が今でも私の事を見ていて、私を楽しませてくださっているのは、猫がまだ姿を表していないからです。鼠である私だけが、毎日そろりと穴から出てきて、遠くから彼女と目を合わしています。
 　彼女の好きな猫が現れたら、私はまた大人しく穴に戻って引きこもるでしょう。
 　そんな私でも、やはり彼女が好きです。私が側にいて差し上げられる時間だけでも、もう少し私を見ていただけませんか。
 　嘉然さんは、これからのあらゆるクリスマスはみんなと一緒にお過ごしになると仰っていました。「みんな」に当てはまる人ってどんな人なんでしょう。この集合に私もエンドサイトーシスしてほしいです。

 　猫ちゃんは未だに嘉然さんが怖いです。
 　彼女の愛する猫は私が連れて来ますから。
 　少しでも油断したら、猫の口に身を滅ぼされます。
 　その時になったら、嘉然さんは私の体をちゃんと繕って、ドアの外へ捨ててくださるんでしょう。
 　そうしたら私はネズミフライに。テヘヘ。
 　できるだけ近い所に捨てていただきたいです。彼女が好きなんですから、これからもずっと。

 　窓越しに部屋の中を覗く我が魂に映ったのは、つけてあった軽く鳴っている鈴と、ソファーに寛いでいらっしゃる嘉然さんと、そして彼女の肩に座っていて大人しく演じているレッドタビーの猫。
 　壁炉の火明かりは彼女の頬を照らして、凍り付いた我が心臓は寒風に揺られて僅かな熱を放つ。)"
 };
POINT getting = {941, 843};
POINT sending = {928, 981};
POINT shortGet = {944, 852};
POINT catByPoint = {990, 872};
bool doflag = false;
const int tire = 20;
int times = tire;
string s, last;
char eANSI[] = "NULL Cboard";
int cnt = 0, dat = 0, key;
char* ptr = nullptr;
string datt;
bool lt, ref = 0;
clock_t time_0;
ofstream ofile("log.txt");
const char* tips[] = {"谨防电信诈骗", "连日来，各地警方普遍开展“敲门行动”、走村入户宣传反电诈，使电信诈骗发案数显著下降。但在，仍有少数群众上当受骗。"
                      , "保管好个人信息，涉及身份证号、验证码、银行卡号、密码等信息，一律保密。", "科技发展的日新月异，信息网络普及我们的生活，但这也让很多不法分子趁虚而入，侵蚀网络空间"
                      , "防范电信诈骗,既要靠公安部门重拳出击,更要靠社会公众自身提高防范意识,自觉远离电信诈骗", "地鼠萎是煞笔"
                     };
char* tosend(string &s) {
	return const_cast<char*>(s.c_str());
}
vector<string> pixiv;
vector<string> yydz;
int _tmain(int argc, _TCHAR* argv[]) {

	prefun();
	Sleep(2000);
	while (1) {
//		if(cnt%10==0&&cnt!=0)
//		{
//			S(600);
//			char ch[100];
//			sprintf(ch,"回复了%d条消息",cnt);
//			qsend(ch);
//		}
		times--;
		if (times == 0) {
			cout << "可选的关闭环节" << endl;
			S(4000);
			times = tire;
			system("cls");
			mgo(sending);
			ent();
		}
		cout << clock() - time_0 << ' ' << endl;
//		if(clock()-time_0>15000)
//		{
//			time_0=clock();
//			qsend(const_cast<char*>(tips[rand()%6]));
//		}
		if (times == 0)return 0;
		S(200);
		cout << times << endl;
		sget();

		char* qg = getCBoard();
		ptr = qg;
		s = string(qg);
		if(s.find("一眼")!=s.npos||s.find("顶针")!=s.npos||s.find("丁真")!=s.npos||s.find("义演")!=s.npos)
		{
			findpic2();
		}
		cout << "key:" << key << endl;
		cerr << ref << endl;
		if (!s.empty() && ref && s != eANSI) {
			S(500)
			qsend(qg);
			S(500)
		}
		if (last != s && s != eANSI)
			ofile << s;
		if (s != eANSI)
			last = s;
		//cout << qg << endl;//if(qg!=eANSI)for (int i = 0; i < strlen(qg); ++i)cerr<<i<<' '<<(int)qg[i]<<endl;
		if (findsl(qg))
			jielong(strlen(qg));
		if (qg[1] == '#' || qg[0] == '#') {
			command();
		}
		ptr = nullptr;
		if (dat > 0) {
			dat--;
			qsend(tosend(datt));
			S(600)
		}
		if (dat == 0 && lt == 1) {
			qsend("");
		}

		if (dat == 0)
			lt = 0;
		cleanCBoard();
		continue;
	}
}
bool findsl(char* qg) {
	if (qg[0] == -95 && qg[1] == -83) {
		for (int i = 0; i < strlen(qg) - 2; i += 2) {
			if (qg[0] != -95 || qg[1] != -83)
				goto next;

		}
	} else goto next;
	return true;
next:
	for (int i = 0; i < strlen(qg); ++i) {
		if ((int)qg[i] < 1)return false;
		if (qg[i] == '@')return false;
		if ((int)qg[i] < 32 )continue;
		if (qg[i] != '.')
			return false;
	}
	return true;
}
void findpic() {
	string s;
	string path = "C:\\desktop.2.0\\QQrob\\pic\\pixiv\\";
	{
		s = path;
		s += pixiv[rand() % pixiv.size()];
		cout << s << endl;
		CopyFileToClipboard(const_cast<char*>(s.c_str()));
		s.clear();
		mgo(sending);
		S(50)
		mdown;
		mup;Sleep(50);
		keybd_event(17, 0, 0, 0);
		keybd_event(86, 0, 0, 0);Sleep(50);
		keybd_event(17, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(86, 0, KEYEVENTF_KEYUP, 0);Sleep(50);
		keybd_event(13, 0, 0, 0);
		keybd_event(13, 0, KEYEVENTF_KEYUP, 0);Sleep(50);
	}
}
void pre2()
{
	string inPath = "C:\\desktop.2.0\\QQrob\\pic\\yydz\\*";//遍历文件夹下的所有文件
	//用于查找的句柄
	long long handle;
	struct _finddata_t fileinfo;
	//第一次查找
	handle = _findfirst(inPath.c_str(), &fileinfo);
	if (handle == -1)
		return ;
	do {
		if (fileinfo.name != "." && fileinfo.name != "..")
			yydz.push_back(fileinfo.name);
		//printf("%s\n",fileinfo.name);
		
	} while (!_findnext(handle, &fileinfo));	
}
void pre1()
{
	string inPath = "C:\\desktop.2.0\\QQrob\\pic\\piviv\\*";//遍历文件夹下的所有文件
	//用于查找的句柄
	long long handle;
	struct _finddata_t fileinfo;
	//第一次查找
	handle = _findfirst(inPath.c_str(), &fileinfo);
	if (handle == -1)
		return ;
	do {
		if (fileinfo.name != "." && fileinfo.name != "..")
			pixiv.push_back(fileinfo.name);
		//printf("%s\n",fileinfo.name);
		
	} while (!_findnext(handle, &fileinfo));
}
void findpic2() {
	string s;
	string path = "C:\\desktop.2.0\\QQrob\\pic\\yydz\\";
	{
		s = path;
		s += yydz[rand() % yydz.size()];
		cout << s << endl;
		CopyFileToClipboard(const_cast<char*>(s.c_str()));
		Sleep(50);
		s.clear();
		mgo(sending);
		S(50)
		mdown;
		mup;Sleep(50);
		keybd_event(17, 0, 0, 0);
		keybd_event(86, 0, 0, 0);Sleep(50);
		keybd_event(17, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(86, 0, KEYEVENTF_KEYUP, 0);Sleep(50);
		keybd_event(13, 0, 0, 0);
		keybd_event(13, 0, KEYEVENTF_KEYUP, 0);Sleep(50);
	}
}
void command() {
	if (s.find(to_string(key)) != string::npos) {
		key = rand();
		if (s.find("pic") != string::npos) {
			S(200)
			findpic();
			S(1000)
		} else if (s.find("break") != string::npos)
			exit(0);
		else if (s.find("reflect") != string::npos) {
			ref = 1;
		}
	} 	else if (s.find("stop") != string::npos) {
		ref = 0;
		dat = 0;
	} else if (s.find("reflect") != string::npos) {
		if (strlen(ptr) > 100)
			qsend("内容过长");
		else
			qsend(const_cast<char*>(s.substr(s.find("reflect") + 7).c_str()));
	} else if (s.find("at") != string::npos) {
		datt.clear();
		datt.push_back('@');
		int x = s.find("at");
		if (x == string::npos) {
			qsend("Error:No name");
			return;
		}
		int y = s.find("^");
		if (y == string::npos) {
			qsend("Error:No times");
			return;
		}
		string pname = s.substr(x + 3, y - x - 4);
		if (pname == "ddv")
			pname = "herobrine64";
		else if (pname == "mq")
			pname = "啊呖呖啊呖呖";
		else if (pname == "玄孙")
			pname = "老祖宗";
		else if (pname == R"(春春的飞舞)" || pname == "xzl" || pname == "小号") {
			qsend("禁止at我");
			return;
		}
		datt.append(pname);
		dat = stoi(s.substr(y + 1));
		if (dat < 0) {
			qsend("格式错误");
			return ;
		}
		if (dat > 10) {
			dat = 0;
			qsend("at这么多次会被@herobrine64禁言的");
			return;
		}
		lt = 1;
	} else if (s.find("ddv") != string::npos) {
		char dv[7][10] = {
			"114514", "1919810", "1376666", "夹心糖", "野兽先辈", "顶针", "SB"
		};
		char out[100] = "ddv is ";
		strcat(out, dv[rand() % 7]);
		qsend(out);
	} else if (s.find("list") != string::npos) {
		qsend("这是 @春春的飞舞 写的机器人\n命令以\"#\"开头\n输入list查看当前支持命令\n输入ddv计算今日运势\n输入text查看小作文\n输入I am sb查看(  )\n输入reflect复述你现在所说的话(好像一点用处都没有)\n输入at sb^ (这里有空格)次数启动代at某人服务\n输入stop停止管理端的reflect和at某人");
	} else if (s.find("text") != string::npos) {
		S(200)
		qsend(const_cast<char*>(xzw[rand() % 20]));
		S(300)
	} else if (s.find("I am sb") != string::npos) {
		S(200)
		findpic();
		S(1000)
	} else {
		qsend("Unknown Command");
	}
}
int CopyFileToClipboard(char szFileName[])
{
	UINT uDropEffect;
	HGLOBAL hGblEffect;
	LPDWORD lpdDropEffect;
	DROPFILES stDrop;
	HGLOBAL hGblFiles;
	LPSTR lpData;
	uDropEffect = RegisterClipboardFormat("Preferred DropEffect");
	hGblEffect = GlobalAlloc(GMEM_ZEROINIT | GMEM_MOVEABLE | GMEM_DDESHARE,sizeof(DWORD));
	lpdDropEffect = (LPDWORD)GlobalLock(hGblEffect);
	*lpdDropEffect = DROPEFFECT_COPY;//复制; 剪贴则用DROPEFFECT_MOVE
	GlobalUnlock(hGblEffect);
	stDrop.pFiles = sizeof(DROPFILES);
	stDrop.pt.x = 0;
	stDrop.pt.y = 0;
	stDrop.fNC = FALSE;
	stDrop.fWide = FALSE;
	hGblFiles = GlobalAlloc(GMEM_ZEROINIT | GMEM_MOVEABLE | GMEM_DDESHARE,\
	sizeof(DROPFILES)+strlen(szFileName)+2);
	lpData = (LPSTR)GlobalLock(hGblFiles);
	memcpy(lpData,&stDrop,sizeof(DROPFILES));
	strcpy(lpData+sizeof(DROPFILES),szFileName);
	GlobalUnlock(hGblFiles);
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_HDROP,hGblFiles);
	SetClipboardData(uDropEffect,hGblEffect);
	CloseClipboard();
return 1;
}
void jielong(int len) {
	if (len >= 90)
		len = 90;
	char c[3];
	char ans[1024];
	strcpy(c, ".");
	strcpy(ans, ".");
	for (int i = 1; i < len - 1; ++i) {
		strcat(ans, c);
	}
	S(50)
	cout << ans << endl;
	qsend(ans);
}
void prefun() {
	QWrite();
	throwQFile();
	srand(time(0));
	cleanCBoard();
	key = rand();
	time_0 = clock();
	pre1();
	pre2();
}


void sget() {
	mgo(shortGet);
	S(10);
	mrdown;
	mrup;
	S(10);
	mgo(catByPoint);
	S(10);
	mdown;
	mup;
}

wchar_t* AnsiToUnicode( const char* szStr ) {
	int nLen = MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szStr, -1, NULL, 0 );
	if (nLen == 0) {
		return NULL;
	}
	wchar_t* pResult = new wchar_t[nLen];
	MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szStr, -1, pResult, nLen );
	return pResult;
}


void qsend(char* ch) {
	++cnt;
	QWnd;
	mgo(sending);
	S(50)
	mdown;
	mup;
	S(50)
	StringToClipBoard(ch);
	S(50);
	stick();
	S(50)
	ent();
	cleanCBoard();
}

void getinf() {
	Qwnd;
	mgo(getting);
	mdown;
	mup;
	allcat();
}

void allcat() {
	kdown(17)
	kdown(65)
	kup(17)
	kup(65)
	kdown(17)
	kdown(67)
	kup(17)
	kup(67)
}

void cat() {
	kdown(17)
	kdown(67)

	kup(17)
	kup(67)
}

void ent() {
	kdown(13)
	kup(13)
}

void stick() {
	kdown(17)
	kdown(86)
	kup(17)
	kup(86)
}

void QWrite() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

HWND qHWND() {
	S(2000)
	GetCursorPos(pQset);
	Qwnd = 	WindowFromPoint(Qset);
	return Qwnd;
}

BOOL StringToClipBoard(char* srcString) {
	BOOL bResult = FALSE;
	DWORD dwLength = strlen(srcString);
	HANDLE hGlobalMemory = GlobalAlloc(GHND, dwLength + 1); // 分配内存
	LPBYTE lpGlobalMemory = (LPBYTE)GlobalLock(hGlobalMemory); // 锁定内存
	if ( NULL != lpGlobalMemory ) {
		strcpy((char*)lpGlobalMemory, srcString);
		::GlobalUnlock(hGlobalMemory); // 锁定内存块解锁
		::OpenClipboard(NULL); // 打开剪贴板
		::EmptyClipboard(); // 清空剪贴板
		::SetClipboardData(CF_TEXT, hGlobalMemory); // 将内存中的数据放置到剪贴板
		::CloseClipboard();

		bResult = TRUE;
	}
	return bResult;
}
void cleanCBoard() {
	HWND hWnd = NULL;
	OpenClipboard( hWnd );//打开剪切板
	EmptyClipboard();//清空剪切板
	CloseClipboard();//关闭剪切板
}
void writeCBoard() {
	HWND hWnd = NULL;
	OpenClipboard( hWnd );//打开剪切板
	EmptyClipboard();//清空剪切板
	HANDLE hHandle = GlobalAlloc(GMEM_FIXED, 1000);//分配内存
	char* pData = (char*) GlobalLock(hHandle);//锁定内存，返回申请内存的首地址
	strcpy(pData, "123"); //或strcpy(pData, "this is a ClipBoard Test.");
	SetClipboardData(CF_TEXT, hHandle);//设置剪切板数据
	GlobalUnlock(hHandle);//解除锁定
	CloseClipboard();//关闭剪切板
}
char* getCBoard() {
	char *url, *pData;
	size_t length;
	OpenClipboard(NULL);
	HANDLE hData = GetClipboardData(CF_TEXT);
	//assert(hData!=NULL);
	if (hData == NULL) {
		HANDLE hdata = GetClipboardData(CF_UNICODETEXT);
		if (hdata == NULL)
			return eANSI;
		return "unicode";
	}
	length = GlobalSize(hData);
	url = (char*)malloc(length + 1);
	pData = (char*)GlobalLock(hData);
	strcpy(url, pData);
	GlobalUnlock(hData);
	CloseClipboard();
	url[length] = 0;
	return url;
}
void throwQFile() {
	if (getSysVersion() > 9.99) {
		HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
		DWORD mode;
		GetConsoleMode(hStdin, &mode);
		mode &= ~ENABLE_QUICK_EDIT_MODE;
		SetConsoleMode(hStdin, mode);
		cout << "已移除快速编辑模式" << "\n" << endl;
	}
}

float getSysVersion() {
	float f_ret;
	typedef void(__stdcall * NTPROC)(DWORD*, DWORD*, DWORD*);
	DWORD dwMajor, dwMinor, dwBuildNumber;
	NTPROC proc = (NTPROC)GetProcAddress(
	                  LoadLibrary("ntdll.dll"),
	                  "RtlGetNtVersionNumbers"
	              );
	proc(&dwMajor, &dwMinor, &dwBuildNumber);
	// win 10
	if (dwMajor == 10 && dwMinor == 0) {
		f_ret = dwMajor + dwMinor * 0.1;
		return f_ret;
	}
	// win 8.1
	if (dwMajor == 6 && dwMinor == 3) {
		f_ret = dwMajor + dwMinor * 0.1;
		return f_ret;
	}
	// win 8.1 以下
	SYSTEM_INFO info;
	GetSystemInfo(&info);
	OSVERSIONINFOEX os;
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
#pragma warning(disable:4996)
	if (GetVersionEx((OSVERSIONINFO *)&os)) {
		f_ret = os.dwMajorVersion + os.dwMinorVersion * 0.1;
	}
	return f_ret;
}
