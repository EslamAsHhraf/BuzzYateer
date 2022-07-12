
<div align="center">

# <img align="center" width=70px height=70px src="https://media3.giphy.com/media/BnHmTSiDBsMr1Kaji7/giphy.gif?cid=ecf05e47vlop8zc7443qhtltuxiq8j926ujkvnx1k71kt9oy&rid=giphy.gif&ct=g"> BuzzYateer (وقيادة الكوكب)


   <img width=100%  src="https://rapidapi.com/blog/wp-content/uploads/2018/06/web-animation-gif.gif" alt="logo">
</div>

<p align="center"> 
    <br> 
</p>

## <img align= center width=50px height=50px src="https://thumbs.gfycat.com/HeftyDescriptiveChimneyswift-size_restricted.gif"> Table of Contents

- <a href ="#about"> 📙 overview</a>
- <a href ="#Started"> 💻 Get Started</a>
- <a href ="#Work"> ⚙️   How project Work</a>
- <a href ="#Screenshots"> 📷 Demo Screenshots</a>
- <a href ="#Structure"> 📁  File Structure</a>
- <a href ="#Contributors"> ✨ Contributors</a>
<hr style="background-color: #4b4c60"></hr>

## <img align="center"  width =60px  height =70px src="https://media2.giphy.com/media/Yn4nioYWSZMqiPNVuD/giphy.gif?cid=ecf05e47m5h78yoqhdkg8pq54o5qsxhdoltjxyfe08d4vxvg&rid=giphy.gif&ct=s"> overview <a id = "about"></a>

<ul>
<li>
In the hope of getting to know more about Mars and the possibility of life on its surface, a huge number of exploratory missions to different regions of the planet need to be conducted.
 </li>
 <li>
 Imagine (at some future time) that we have several rovers of different types and capabilities on the surface of Mars ready to carry out missions to its different regions. 
 </li>
  <li>
 There is also a hypothetical base station which acts as the central point from which the different rovers begin their exploratory missions and to which they return after mission completion. 
 </li>
 <li>
The base station basically assigns missions to the different rovers.
</li>
</ul>

<hr style="background-color: #4b4c60"></hr>

## <img align= center width=50px height=50px src="https://media0.giphy.com/media/QvpqIQAAl66EfoTJj8/200w.webp?cid=ecf05e47kn4j0qln8fk4xybgqwle0nju8stj9hjw4z6fk8c2&rid=200w.webp&ct=s"> Get Started <a id = "Started"></a>

<ol>
<li>Clone the repository

```
git clone https://github.com/AdhamAliAbdelAal/BuzzYateer
```
</li>
<li>
Main File is

```
Buzz Yateer\Buzz Yateer\Buzz Yateer.sln
```
</li>
<li>
Read <a href="https://github.com/EslamAsHhraf/Serial-Peripheral-Interface/blob/master/CMP1030%20Project%20Description.pdf">Project Description</a> to undertand project vey well
</li>
</ol>
<hr style="background-color: #4b4c60">

## <img align= center width=50px height=50px src="https://media3.giphy.com/media/ViCO3ua8uHhhA2ZQ4J/giphy.gif?cid=ecf05e47yeo8vftfrfkkie7ewyvfwkwon92tsapvyhevi9iv&rid=giphy.gif&ct=s"> How project Work <a id ="Work"></a>
<ol>
<li>After each CLK the Master chose The Slave Again with CS with Enable One Slave and Disable the Other.</li>
<li>At Test Bench of the Master is to Send and Receive data from many Slaves at Same Time This Is Mainly Testing the ability Of the Exchange Between the Master and Many Slaves.</li>
<li>At Test Bench of The Slave Is to Receive Data from Master and makes shift Operation and Resend Shifted Data.</li>
</ol>
<hr>

<table>
  <thead >
         <th style="text-align: center;"> </th>
         <th style="text-align: center;"> List Name</th>
         <th style="text-align: center;">Chosen DS</th>
         <th style="text-align: center;">Justification</th>
  </thead>
  <tr>
     <td align="center">1</td>
      <td align="center">Events List</td>
      <td align="center">Queue</td>
      <td align="center">First event declared will have been done first. Queue will be based on linked list because it Insert in the end.</td> 
  </tr>
  <tr>
     <td align="center">2</td>
      <td align="center">Waiting Polar Missions</td>
      <td align="center">Queue</td>
      <td align="center">First mission declared will have been done first. Queue will be based on linked list because it
easier to Insert in the end and delete from front.</td> 
  </tr>
  <tr>
     <td align="center">3</td>
      <td align="center">Waiting Mountainous Missions</td>
      <td align="center">Queue</td>
      <td align="center">First mission declared will have been done first. Queue will be based on linked list because it.
easier to Insert in the end and delete from front.</td> 
  </tr>
  <tr>
     <td align="center">4</td>
      <td align="center">Waiting Emergency Missions</td>
      <td align="center">Priority Queue</td>
      <td align="center">Because we want to sort them according to their priority. Queue will be based on linked list because it easier to Insert in any position and delete from front.</td> 
  </tr>
  <tr>
     <td align="center">5</td>
      <td align="center">Execution Missions</td>
      <td align="center">Priority Queue</td>
      <td align="center">Because we want to sort them
        according to the day will done
        on. Queue will be based on
        linked list because it easier to
        Insert in any position and
        delete from front.</td> 
  </tr>
  <tr>
     <td align="center">6</td>
      <td align="center">Completed Missions</td>
      <td align="center">Queue</td>
      <td align="center">Because it will be print the
completed mission
every day. Queue will based on
linked list because it
easier to Insert in the end.</td> 
  </tr>
  <tr>
     <td align="center">7</td>
      <td align="center">Polar Rovers</td>
      <td align="center">Priority Queue</td>
      <td align="center">Because we want to sort them
according to their velocity.
Queue will be based on linked
list because it easier to Insert
in any position and delete
from front.</td> 
  </tr>
  <tr>
     <td align="center">8</td>
      <td align="center">Mountainous Rovers</td>
      <td align="center">Priority Queue</td>
      <td align="center">Because we want to sort them
according to their velocity.
Queue will be based on linked
list because it easier to Insert
in any position and delete
from front.</td> 
  </tr>
  <tr>
     <td align="center">9</td>
      <td align="center">Emergency Rovers</td>
      <td align="center">Priority Queue</td>
      <td align="center">Because we want to sort them
according to their velocity.
Queue will be based on linked
list because it easier to Insert
in any position and delete
from front.</td> 
  </tr>
  <tr>
     <td align="center">10</td>
      <td align="center">Execution Rovers</td>
      <td align="center">Priority Queue</td>
      <td align="center">Because we want to sort them
according to the day will done
mission. Queue will be based
on linked list because it easier
to Insert in any position and
delete from front.</td> 
  </tr>
  <tr>
     <td align="center">11</td>
      <td align="center">Checkup Rovers</td>
      <td align="center">Priority Queue</td>
      <td align="center">Because we want to sort them
according to less time will take
in checkup. Queue will be
based on linked list because it
easier to Insert in any position
and delete from front.</td> 
  </tr>
  <tr>
     <td align="center">12</td>
      <td align="center">Rovers Maintenance</td>
      <td align="center">Priority Queue</td>
      <td align="center">Because we want to sort them according to less time will take in maintenance.</td> 
  </tr>
  </table>
<hr style="background-color: #4b4c60"></hr>

## <img  align="center" width= 70px height =55px src="https://media0.giphy.com/media/Xy702eMOiGGPzk4Zkd/giphy.gif?cid=ecf05e475vmf48k83bvzye3w2m2xl03iyem3tkuw2krpkb7k&rid=giphy.gif&ct=s"> Contributors <a id ="Contributors"></a>

<table align="center" >
  <tr>
    <td align="center"><a href="https://github.com/AdhamAliAbdelAal" ><img src="https://avatars.githubusercontent.com/u/83884426?v=4" width="150px;" alt=""/><br /><sub><b>Adham Ali</b></sub></a><br />
    </td>
     <td align="center"><a href="https://github.com/EslamAsHhraf"><img src="https://avatars.githubusercontent.com/u/71986226?v=4" width="150px;" alt=""/><br /><sub><b>Eslam Ashraf</b></sub></a><br /></td>
  </tr>
</table>
