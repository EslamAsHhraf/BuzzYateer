
<div align="center">

# <img align="center" width=70px height=70px src="https://media1.giphy.com/media/SvRxmoLTkkDkrt5G8N/giphy.gif?cid=790b761179c01e9772b517ed24244b935fae2a2d73b5dd24&rid=giphy.gif&ct=s"> Buzz Yateer (وقيادة الكوكب)


   <img   src="https://user-images.githubusercontent.com/71986226/178483471-00d2bfb6-7f5f-4180-9db9-61e02a61e6e3.gif" alt="logo">

  ### إلى اللانهائية وما بعدها🚀
  ### To infinity and beyond!🚀

</div>

<p align="center"> 
    <br> 
</p>

## <img align= center width=50px height=50px src="https://user-images.githubusercontent.com/71986226/178468913-84c3151c-e8d1-4420-a9e9-b2434e9c2f75.gif"> Table of Contents

- <a href ="#about"> 📙 overview</a>
- <a href ="#Started"> 💻 Get Started</a>
- <a href ="#Work"> ⚙️   How project Work</a>
- <a href ="#Work"> 🧱   Chosen Data Structure</a>
- <a href ="#Screenshots"> 📷 Demo Screenshots</a>
- <a href ="#Video">  📽 GIF Demo</a>
- <a href ="#Contributors"> ✨ Contributors</a>
- <a href ="#License"> 🔒 License</a> 
<hr style="background-color: #4b4c60"></hr>

## <img align="center"  width =70px  height =70px src="https://media0.giphy.com/media/3OXc5iM4VybLzKAoBR/giphy.gif?cid=ecf05e478qsaq6znpjyqsmzzkbay2vl1giu97cqmksizmblk&rid=giphy.gif&ct=s"> overview <a id = "about"></a>

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

## <img align= center width=70px height=70px src="https://user-images.githubusercontent.com/71986226/178401569-979cab38-b95c-4c22-a497-4d368e2ef415.gif"> Get Started <a id = "Started"></a>

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
Read <a href="https://github.com/AdhamAliAbdelAal/BuzzYateer/blob/master/Project_Description.pdf">Project Description</a> to undertand project vey well
</li>
</ol>
<hr style="background-color: #4b4c60">

## <img align= center width=80px height=80px src="https://media3.giphy.com/media/BnHmTSiDBsMr1Kaji7/giphy.gif?cid=ecf05e47vlop8zc7443qhtltuxiq8j926ujkvnx1k71kt9oy&rid=giphy.gif&ct=g"> How project Work <a id ="Work"></a>
<ol>
<li>Put input in the <a href="https://github.com/AdhamAliAbdelAal/BuzzYateer/blob/master/Buzz%20Yateer/Buzz%20Yateer/Input.txt">Input.txt</a></li>
<li>Run the main file.</li>
<li>You should choose the mode of output.

<ul>
  <li> <p>1) Interactive Mode</p>
   Interactive Mode Allows user to monitor the missions and rovers. The program should print an output like that shown below. In this mode, the program prints the current day then pauses for an input from the user (“Enter” key for example) to display the output of the next day
   </li>
  <li> <p> 2) Step-By-Step Mode</p>
  Step-By-Step Mode is identical to the interactive mode except that after each day, the program waits for one second (not for user input) then resumes automatically.
  </li>
  <li> <p>4) Silent Mode</p>
  the program produces only an output file (See the “File Formats” section
   </li>
   <br>
</ul>
</li>
<li>No matter what mode of operation your program is running in, <a href="https://github.com/AdhamAliAbdelAal/BuzzYateer/blob/master/Buzz%20Yateer/Buzz%20Yateer/Output.txt">Output.txt</a> file should be produced. </li>
</ol>

<hr style="background-color: #4b4c60"></hr>


## <img align= center width=70px height=70px src="https://user-images.githubusercontent.com/71986226/178469374-15498392-26a1-4ba0-99d7-9ce899c131f0.gif"> Chosen Data Structure <a id = "Started"></a>
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

## <img align= center width=70px height=70px src="https://user-images.githubusercontent.com/71986226/178469533-b83a81eb-c3fa-4d05-83b6-c0dbe4bd8e4b.gif"> Demo Screenshots <a id ="Screenshots"></a>

 <img  align= center src="https://user-images.githubusercontent.com/71986226/178465115-586eac4c-ff3d-4737-8d65-9b41b4f93e17.png">
 
<hr style="background-color: #4b4c60"></hr>

  <img  align= center src="https://user-images.githubusercontent.com/71986226/178464999-217021bd-f4bd-4f2f-9e22-d7ee53d77cd8.png">
<hr style="background-color: #4b4c60"></hr>

## <img  align= center width= 70px height =70px src="https://user-images.githubusercontent.com/71986226/178469742-c15f5e51-ba32-4dec-89a0-98b3edb2e941.gif"> GIf Demo <a id ="Video"></a>

<img  align= center src="https://user-images.githubusercontent.com/71986226/178468453-8ab84cac-b7a1-4f02-b140-25ce88f05662.gif">

<hr style="background-color: #4b4c60"></hr>

## <img  align="center" width= 80px height =70px src="https://media4.giphy.com/media/iWmH3uMKRNO2QQVyLk/giphy.gif?cid=ecf05e479h6502aw1xdd8d1q9bj936dt7jg0r1d1kw62s3l1&rid=giphy.gif&ct=s"> Contributors <a id ="Contributors"></a>

<table align="center" >
  <tr>
   <td align="center"><a href="https://github.com/MohamedWw" ><img src="https://avatars.githubusercontent.com/u/64079821?v=4" width="150px;" alt=""/><br /><sub><b>Mohamed Walid</b></sub></a><br />
    </td>
    <td align="center"><a href="https://github.com/AbdelrahmanAshrafMohamedelsayed" ><img src="https://avatars.githubusercontent.com/u/97232730?v=4" width="150px;" alt=""/><br /><sub><b>Abdelrahman Ashraf</b></sub></a><br />
    </td>
    <td align="center"><a href="https://github.com/AdhamAliAbdelAal" ><img src="https://avatars.githubusercontent.com/u/83884426?v=4" width="150px;" alt=""/><br /><sub><b>Adham Ali</b></sub></a><br />
    </td>
     <td align="center"><a href="https://github.com/EslamAsHhraf"><img src="https://avatars.githubusercontent.com/u/71986226?v=4" width="150px;" alt=""/><br /><sub><b>Eslam Ashraf</b></sub></a><br /></td>
  </tr>
</table>

## License <a id ="License"></a>

> This software is licensed under MIT License, See [License](https://github.com/AdhamAliAbdelAal/BuzzYateer/blob/master/LICENSE) for more information ©AdhamAliAbdelAal.
