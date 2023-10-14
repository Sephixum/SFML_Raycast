<h1 align="center"> SFML raycasting engine </h1>

<!-- TABLE OF CONTENTS -->
<h2 id="table-of-contents"> :book: Table of Contents</h2>

<details open="open">
    <summary> Table of contents </summary>
    <o1>
    <li><a href="#about-the-project"> ➤ About The Project</a></li>
    <li><a href="#overview"> ➤ Overview</a></li>
    <li><a href="#project-files-description"> ➤ Project Files Description</a></li>
    <li><a href="#getting-started"> ➤ Getting Started</a></li>
    <li><a href="#references"> ➤ References</a></li>
    <li><a href="#credits"> ➤ Credits</a></li>
    </o1>
</details>

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<!-- ABOUT THE PROJECT -->
<h2 id="about-the-project"> :pencil: About The Project</h2>
<p align="justify">
    I alway had the dream of combining math and programming in hopes of creating cool stuff with them,
so after spending a bit of time searching I got advised to enter the world of graphics programming. this
was my first choice as a project for this topic.
</p>

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<!-- OVERVIEW -->
<h2 id="overview"> :cloud: Overview</h2>

<p align="justify"> 
This project is a simple implementation of a raycasting engine which will render a pseudo 3D world
using 2D linear algebra calculations in order to cast rays and render the world based on them. Basically the further the ray is stopped and has hit a wall, smaller the height of the wall will be which is a stripe with length of one pixel.
</p>

![Gif not found](Showcase.gif)

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<!-- PROJECT FILES DESCRIPTION -->
<h2 id="project-files-description"> :floppy_disk: Project Files Description</h2>

<!-- <p align="justify">  -->
Headers and source files are separated into to different directories, `include` and `src`.
Source files are all in `src` and defined headers are in `include`.
<!-- </p> -->


<ul>
<li><b>Globals.hpp</b> - Where all Global settings are stored.</li>
<li><b>MyFuncs.hpp</b> - Where commonly used functions are declared.</li>
  <li><b>Game.hpp</b> - Where all configuration of the application window and events are done.</li>
  <li><b>Map.hpp</b> - Where map and its logics are set up.</li>
  <li><b>MyTriangle.hpp</b> - This is a Draw able sprite for the map.</li>
  <li><b>Player.hpp</b> - Configuration for camera which is the player's eye.</li>
</ul>

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<!-- GETTING STARTED -->
<h2 id="getting-started"> :book: Getting Started</h2>

<p>At first clone the repository:</p>
<pre><code>$ git clone https://github.com/Sephixum/SFML_Raycast.git</code></pre>

<p>As an exmaple you can first generate a build directory for cmake:</p>
<pre><code>$ cmake -S . -B build</code></pre>

<p>Build and compile:</p>
<pre><code>$ cmake --build build</code></pre>

<p>You can run the project:</p>
<pre><code>$ ./build/raycasting</code></pre>

<h3>Usage</h3>
<p>You can move around the map using <code>W</code> <code>A</code> <code>S</code> <code>D</code>.</p>
<p>Camera can be rotated with keys <code>H</code> (anticlockwise) and <code>L</code> (clockwise).</p>
<p>Arrow key <code>Down</code> and <code>Up</code> can be used to increase of decrease vision density.</p>
<p>You can reset your vision density with <code>R</code>.</p>

<!-- <i>Note that all of the commands that appear in this project also appear in <code>commands.txt</code>, for easy copying and pasting.</i> -->

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<!-- REFRENCES -->
<h2 id="references"> :notebook_with_decorative_cover: References</h2>

<p>I have been studying concepts from
<a href="https://lodev.org/cgtutor/raycasting.html"> Lode's Ray Casting Tutorial</a>
so here is the link for it.</p>

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<!-- Credits -->
<h2 id="credits"> :scroll: Credits</h2>
<p>Special thanks to my dear friend <a href="https://github.com/MiliAxe">MiliAxe</a> for aiding me in designing and releasing this project.</p>
