# NaichenCon 使用手冊

:::warning
**目錄**
[TOC]
:::

# SDVX controller 第二代

* 商品型號：NC-2
* 商品定價： $3300↓ NTD (簡約款) / $3300 NTD (基本款) / $3700 NTD (升級款)
* 購買連結：https://forms.gle/Pn5Pygji2yAFHeG47
* 聯絡資訊：[FB粉絲專頁](https://www.facebook.com/NaichenCon/)

## Development Setup

1. Follow [Sparkfun Pro Micro Hookup Guide](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide) to install required board information.
2. Follow the instruction in [Joystick Library](https://github.com/MHeironimus/ArduinoJoystickLibrary).

# 軟體更新紀錄

:::danger
目前最新版本 : v2.1
:::

* 2020/10/10 v2.1 ***新增介面"旋鈕反向"**。

# 模式介紹

NaichenCon對應**兩種輸入模式**與**燈光開關**

:::info
在接上電腦前請先按住兩顆FX鍵(黃鍵)，接上後會看到Start + BT_A + BT_B亮起來，此時代表已經進入模式調整介面(以下簡稱設定)。
:::

### 按鍵燈開關

在設定按下Start鍵會開/關每一顆按鍵的LED燈，如果使用的環境較暗，可以手動把LED燈關閉，比較保護眼睛:D。
當你想要繼續有LED的效果時，只要拔掉重新進入設定再按一次Start鍵就會開啟了。

### 輸入類型介紹

在設定下會有BT_A、BT_B亮起，分別對應以下A模式、B模式輸入：

* A模式：白鍵、黃鍵、Start為鍵盤的a~g、旋鈕為滑鼠的X/Y軸(左旋鈕為Y軸、右旋鈕是X軸)

* B模式：白鍵、黃鍵、Start為Joystick(類似PS4的輸入)的0號到6號、旋鈕為Joystick(類似PS4的輸入)的X/Y軸(左旋鈕為Y軸、右旋鈕是X軸)

### 旋鈕反轉 *10/10新增

在設定下會有BT_C亮起，若當前的右旋鈕是滑鼠x軸、左旋鈕是滑鼠y軸，按下BT_C鍵即可交換，變成右旋鈕是滑鼠y軸、左旋鈕是滑鼠x軸，重新進到設定再按一次就會變回來。此設定在Joystick模式也對應。

:::info
常見使用的模擬器：[K-shoot Mania](https://www.kshootmania.com/)...等等，都可以支援喔~
:::

### 保固

* 本手台之保固為下訂日起算7個月(也就是到您手上後約**半年期間**)。
* 非人為造成之故障排除在保固內皆不收費。
* 人為造成之故障例如：面板碎裂、按鍵碎裂、電路板接頭損壞...等等在保固內收取零件8折之費用。

:::success
寄送資料 (7-11店到店)

姓名：---

手機：---

E-mail：kuya5220@gmail.com

門市名稱：君品門市 (淡水)
:::


### 注意事項

1. 面板採用**磁吸式**固定，在搬運的時候請注意不要只拎著面板喔!。

### 常見問題

---

![](https://i.imgur.com/hAHqyHg.png) **我的按鍵燈沒有關，但是有按鍵不會亮了?**


![](https://i.imgur.com/Iggxffx.png) **請將不會亮的按鍵之微動架拆下來，看看燈泡是不是鬆掉了，只要重新接回去即可，若以上步驟燈泡都沒有亮，請從替換工具包內更換一顆燈泡。**


---

![](https://i.imgur.com/hAHqyHg.png) **我的電腦讀不到手台?**


![](https://i.imgur.com/Iggxffx.png) **目前還在統計有問題的情況，若有此情形請從粉絲團聯絡我。**

---

![](https://i.imgur.com/hAHqyHg.png) **我不會從遊戲內設定?**


![](https://i.imgur.com/Iggxffx.png) **Google過也看不懂的話請從粉絲團聯絡我~。**

---

![](https://i.imgur.com/hAHqyHg.png) **我發現旋鈕or按鍵的線端掉了、斷掉了，該怎麼辦?**


![](https://i.imgur.com/Iggxffx.png) **若您本身有焊接基礎，我可以提供解決步驟，但我建議連同箱子寄回來給我處理，保固內非人為損傷都是免費維修的喔。**

---

![](https://i.imgur.com/hAHqyHg.png) **我的連接線不見了，該怎麼辦?**


![](https://i.imgur.com/Iggxffx.png) **款式為前、後開式的手台，請找micro USB數據傳輸線或是安卓手機數據傳輸線，若為側開式的手台，請找USB type-A to type-B(或是方頭數據線之類的，如下圖)。**

![](https://i.imgur.com/ssotdX8.png)

---

![](https://i.imgur.com/hAHqyHg.png) **我的旋鈕卡住了，轉起來很緊怎麼辦?**


![](https://i.imgur.com/Iggxffx.png) **通常是旋鈕帽鬆掉了，看一下旋鈕帽是不是可以用手拔起來，若是這樣的情況只要用替換工具包內的L型六角起子重新調整高度後轉緊就可以了。若以上解決不了，可以看看旋鈕內部是不是有卡到線...等等，若也沒有，請連同箱子寄回來給我處理，保固內非人為損傷都是免費維修的喔。**

---

![](https://i.imgur.com/hAHqyHg.png) **我的手台沒有你說的模式功能怎麼辦?**


![](https://i.imgur.com/Iggxffx.png) **可能是你的軟體沒有在最新版本，如果需要更新功能，請與我聯絡**

---

![](https://i.imgur.com/hAHqyHg.png) **我的遊戲只支援跟現在不同方向的旋鈕，該怎麼辦?**


![](https://i.imgur.com/Iggxffx.png) **如果您的軟體在介面調整模式有C鍵(旋鈕反轉)的選項，直接選擇就可以在當前輸入模式底下調換旋鈕訊號。另外若您沒有，可以拔開面板將插在電路板上的兩個旋鈕的線對調，就可以調換旋鈕訊號了。**

---

![](https://i.imgur.com/hAHqyHg.png) **如何清潔手台呢?**


![](https://i.imgur.com/Iggxffx.png) **側邊的話可以用乾布擦拭或用刷子清掃。面板的話是壓克力，用酒精擦拭即可。**

---

![](https://i.imgur.com/hAHqyHg.png) **在遊戲內旋鈕太敏感(轉太慢)，怎麼辦?**


![](https://i.imgur.com/Iggxffx.png) **遊戲內應該都有調整旋鈕靈敏度的地方，建議可以依照個人感覺調整到適當的靈敏度。**

---

![](https://i.imgur.com/hAHqyHg.png) ****


![](https://i.imgur.com/Iggxffx.png) ****



