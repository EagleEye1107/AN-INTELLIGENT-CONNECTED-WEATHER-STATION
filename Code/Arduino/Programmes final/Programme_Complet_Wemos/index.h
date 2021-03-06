const char index_html_2[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">

<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
    <title>Esi Weather</title>
    <link rel="shortcut icon" href="https://i.ibb.co/PC8DYtT/clouds.png">
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@200&display=swap" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@500&display=swap" rel="stylesheet">
    <script src="path/to/vanilla.js"></script>
    <script src="https://code.jquery.com/jquery-3.5.1.js"></script>
    <link href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js">
    <link href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet">
    <script src="https://kit.fontawesome.com/d7c9c3d618.js"></script>
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.4.1/css/all.css">
    <script src="https://code.highcharts.com/highcharts.js"></script>
    <script src="https://code.highcharts.com/modules/exporting.js"></script>
    <script src="https://code.highcharts.com/modules/export-data.js"></script>
    <script src="https://code.highcharts.com/modules/accessibility.js"></script>
    <script src="https://www.gstatic.com/firebasejs/4.8.1/firebase.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/jquery@3.2.1/dist/jquery.min.js"></script>


</head>

<body>

    <style>
        /*body*/
        
        * {
            outline: none;
        }
        
        html,
        body {
            margin: 0;
            padding: 0;
            scroll-behavior: smooth
        }
        
        body {
            font-family: poppins;
            background-image: url('https://i.ibb.co/QMtQfzq/sky3.jpg');
            background-size: cover;
            background-attachment: fixed;
            box-sizing: border-box;
            overflow-x: hidden;
        }
        
        header {
            width: 100%;
            height: 9vh
        }
        /*main titles and logo*/
        
        #sub {
            margin: 0 30px;
            color: #fff;
            text-shadow: 2px 2px 1px rgba(252, 169, 15, 0.945);
            font-size: 44px;
            font-family: 'poppins';
            text-decoration: none;
            text-align: center;
            font-weight: bolder;
        }
        
        .logo {
            position: fixed;
            float: left
        }
        
        #logoimg {
            width: 140px;
            height: 65px;
            margin-left: 20px;
            margin-top: 7px;
        }
        /*MENUBAR*/
        
        nav {
            z-index: 1000000;
            position: fixed;
            width: 100%;
        }
        
        nav ul {
            list-style: none;
            background: rgba(0, 0, 0, 0);
            overflow: hidden;
            color: #fff;
            text-shadow: 1px 1px 2px rgba(194, 192, 192, 0.877);
            padding: 0;
            text-align: center;
            margin: 0;
            transition: .8s
        }
        
        nav.black {
            background: #fccb43fa;
            backdrop-filter: blur(5px);
        }
        
        nav ul li {
            padding: 20px;
            display: inline-block;
            float: right
        }
        
        nav ul li a {
            text-decoration: none;
            color: #fff;
            font-size: 25px
        }
        
        .menu-icon {
            width: 100%;
            background: #fccb43fa;
            text-align: right;
            box-sizing: border-box;
            padding: 15px 24px;
            cursor: pointer;
            color: #fff;
            display: none
        }
        
        @media(max-width: 780px) {
            nav.black {
                height: 70px;
            }
            body,
            #blur {
                padding-left: 0px;
                text-align: center;
                align-content: center;
                align-items: center;
            }
            .menu {
                display: none;
            }
            .menu li {
                background-color: #fccb43fa;
            }
            #sidebar_btn {
                top: 0px;
            }
            #blur {
                padding-left: 0px;
            }
            .times {
                margin-left: 20px;
            }
            nav {
                margin-left: 0px;
            }
            .container-card {
                align-content: center;
            }
            #logoimg {
                margin-top: 6px;
                height: 50px;
                width: 100px;
                margin-right: 50px;
                opacity: 1;
                float: left;
            }
            .logo {
                position: fixed;
                top: 0;
                margin-top: 0
            }
            nav ul {
                max-height: 0px;
                background: #1A5276;
            }
            #logout_butt {
                text-align: center;
            }
            nav .black ul {
                background: #e7ba3c
            }
            .showing {
                transition: linear;
                max-height: 30em;
                display: block;
                background-color: #7086ff;
            }
            nav ul li {
                box-sizing: border-box;
                width: 100%;
                padding: 24px 0;
                text-align: center;
            }
            .menu-icon {
                display: block;
            }
        }
        /*TIME TABLE*/
        
        .base {
            width: 100%;
            display: grid;
            align-items: center;
            justify-content: center;
            font-weight: 700;
            margin: 120px 0;
        }
        
        .condition-bar {
            display: flex;
            padding: 20px;
            margin: 20px;
            background: rgba(255, 255, 255, .1);
            border-radius: 20px;
            box-shadow: 5px 15px 25px rgba(0, 0, 0, 0.3);
            color: #fff
        }
        
        .cb1,
        .cb2 {
            display: flex
        }
        
        .condition-bar div {
            margin: 15px
        }
        
        .condition-bar .temp a {
            font-size: 550%
        }
        
        .condition-bar .block1 .humid,
        .chor,
        .condition-bar .block2 .press,
        .wind {

            font-size: 25px;
            font-weight: 700
        }
        
        .times {
            background: rgba(255, 255, 255, .1);
            border-radius: 20px;
            display: flex;
            box-shadow: 5px 15px 25px rgba(0, 0, 0, 0.3);
            margin: 10px;
            color: #fff
        }
        
        .times div {
            margin: 20px;
            font-size: 25px;
            font-weight: 700;
            text-align: center
        }
        
        @media screen and (max-width:820px) {
            .base {
                margin: 0;
            }
            .condition-bar {
                display: block;
                justify-content: center;
                text-align: center;
                padding: 8px;
            }
            .cb1,
            .cb2 {
                display: flex;
                justify-content: center
            }
            .times div {
                font-size: 18px;
            }
            .cond-img,
            .temp {
                padding: 0 20px;
            }
        }
        
        @media screen and (max-width:425px) {
            .condition-bar {
                margin: 10px;
                padding: 0;
            }
            .temp {
                font-size: 14px;
            }
            .times {
                display: grid;
                grid-template-rows: 1fr 1fr;
                grid-template-columns: 1fr 1fr;
            }
        }
        /*CARDS GRID*/
        
        .container-card {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(350px, 1fr));
            grid-gap: 30px;
            justify-content: center;
            align-items: center;
            padding: 100px;
            margin: 0 auto;
        }
        
        .card {
            width: 370px;
            align-items: center;
            margin: auto;
        }
        
        .card:hover .card-content {
            transform: rotateY(.5turn)
        }
        
        .card-content {
            text-align: center;
            position: relative;
            padding: 7em;
            transition: transform 2s;
            transform-style: preserve-3d
        }
        
        .front,
        .back {
            position: absolute;
            padding: 2em;
            height: 150px;
            top: 0;
            bottom: 0;
            left: 0;
            right: 0;
            transform-style: preserve-3d;
            backface-visibility: hidden;
            text-align: center;
            border-radius: 20px;
            box-shadow: 5px 15px 25px rgba(0, 0, 0, 0.3)
        }
        
        .front {
            background: rgba(255, 255, 255, 0.151)
        }
        
        .front h3 {
            font-size: 30px;
            transform: translateZ(100px);
            color: #fff;
            backface-visibility: hidden
        }
        
        .front i {
            font-size: 60px;
            transform: translateZ(100px);
            color: #fff;
            backface-visibility: hidden
        }
        
        .back {
            transform: rotateY(.5turn);
            display: block;
            justify-content: center;
            align-items: center;
            background: rgba(255, 255, 255, .1)
        }
        
        .back .realinfo {
            transform: translateZ(100px);
            color: #fff;
            display: flex;
            font-size: 40px;
            justify-content:center;
            font-weight: 700;
            backface-visibility: hidden;
            text-align: center
        }
        
        .back .realinfo1 {
            transform: translateZ(100px);
            color: #fff;
            display: flex;
            font-size: 35px;
            justify-content: space-between;
            font-weight: 700;
            backface-visibility: hidden;
            text-align: center
        }
        /*VIEWGRAPH BUTTON*/
        
        .viewgraph {
            display: inline-block;
            text-decoration: none;
            font-weight: 800;
            text-align: center;
            color: #fff;
            font-size: 1em;
            width: 130px;
            height: 30px;
            padding: 5px;
            border: 1px solid #fff;
            border-radius: 3px;
            transform: translateZ(100px);
            backface-visibility: hidden
        }
        /*BLUR BEHINF THE SIGNUP FORM*/
        
        .bg-modal {
            width: 100%;
            height: 100vh;
            background: rgba(107, 107, 107, 0.192);
            position: absolute;
            top: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            display: none;
            font-family: 'Montserrat', sans-serif;
            backdrop-filter: blur(5px)
        }
        /*SIGNUP FORM*/
        
        .modal-content {
            margin: -10;
            height: 75%;
            width: 60%;
            display: inline-block;
            position: relative;
            margin: 0;
        }
        
        .modal-content .close {
            position: absolute;
            top: -20px;
            right: -20px;
            font-size: 40px;
            transform: rotate(45deg)
        }
        
        .modal-content .close a {
            text-decoration: none;
            color: #fff
        }
        
        .container {
            background-color: #fff;
            border-radius: 20px;
            position: relative;
            overflow: hidden;
            width: 768px;
            max-width: 100%;
            min-height: 480px;
            top: 20px
        }
        
        .container h1 {
            font-weight: 700;
            margin: 0
        }
        
        .container h2 {
            text-align: center
        }
        
        .container p {
            font-size: 14px;
            font-weight: 100;
            line-height: 20px;
            letter-spacing: .5px;
            margin: 20px 0 30px
        }
        
        .container a {
            color: #222;
            font-size: 14px;
            text-decoration: none;
            margin: 15px 0
        }
        
        .container button {
            border-radius: 20px;
            border: 1px solid #308db8;
            background-color: #308db8;
            color: #FFF;
            font-size: 12px;
            font-weight: 700;
            padding: 12px 45px;
            letter-spacing: 1px;
            text-transform: uppercase;
            transition: transform 80ms ease-in
        }
        
        @media (min-width:650px) and (max-width: 830px) {
            .modal-content .close {
                top: -10px;
                right: -10px;
                z-index: 9999999;
            }
            #container {
                width: 90%;
            }
            .overlay-container {
                padding: 0 5px 0 15px
            }
            .container button {
                padding: 10px;
            }
        }
        
        @media (max-width:649px) {
            .container button {
                padding: 10px;
            }
            .modal-content {
                width: 80%;
            }
            #container {
                min-width: 375px;
                margin-left: -10%;
                width: 100%;
            }
            .bg-modal {
                padding-left: 5px;
            }
            .container button {
                padding: 5px;
            }
            .container h1 {
                font-size: 20px;
            }
            .container p {
                font-size: 15px;
                padding-left: 5px;
            }
            .modal-content .close {
                top: -10px;
                right: -20px;
            }
        }
        
        @media (max-width:350px) {
            #container {
                margin-left: 0%;
                width: 70%;
            }
            .modal-content {
                width: 87%;
            }
        }
        
        .container button:active {
            transform: scale(0.95)
        }
        
        .container button:focus {
            outline: none
        }
        
        .container button.ghost {
            background-color: transparent;
            border-color: #FFF
        }
        
        .container form {
            background-color: #FFF;
            display: flex;
            align-items: center;
            justify-content: center;
            flex-direction: column;
            padding: 0 50px;
            height: 100%;
            text-align: center
        }
        
        .container input {
            background-color: #eee;
            border: none;
            padding: 12px 15px;
            margin: 8px 0;
            width: 100%
        }
        
        .form-container {
            position: absolute;
            top: 0;
            height: 100%;
            transition: all .6s ease-in-out
        }
        
        .sign-in-container {
            left: 0;
            width: 50%;
            z-index: 2
        }
        
        .container.right-panel-active .sign-in-container {
            transform: translateX(100%)
        }
        
        .sign-up-container {
            left: 0;
            width: 50%;
            opacity: 0;
            z-index: 1
        }
        
        .container.right-panel-active .sign-up-container {
            transform: translateX(100%);
            opacity: 1;
            z-index: 5;
            animation: show .6s
        }
        
        @keyframes show {
            0%,
            49.99% {
                opacity: 0;
                z-index: 1
            }
            50%,
            100% {
                opacity: 1;
                z-index: 5
            }
        }
        
        .overlay-container {
            position: absolute;
            top: 0;
            left: 50%;
            width: 50%;
            height: 100%;
            overflow: hidden;
            transition: transform .6s ease-in-out;
            z-index: 100
        }
        
        .container.right-panel-active .overlay-container {
            transform: translateX(-100%)
        }
        
        .overlay {
            background: #FF416C;
            background: -webkit-linear-gradient(to right, #007EA7, #80CED7);
            background: linear-gradient(to right, #007EA7, #80CED7);
            background-repeat: no-repeat;
            background-size: cover;
            background-position: 0 0;
            color: #FFF;
            position: relative;
            left: -100%;
            height: 100%;
            width: 200%;
            transform: translateX(0);
            transition: transform .6s ease-in-out
        }
        
        .container.right-panel-active .overlay {
            transform: translateX(50%)
        }
        
        .overlay-panel {
            position: absolute;
            display: flex;
            align-items: center;
            justify-content: center;
            flex-direction: column;
            padding: 0 40px;
            text-align: center;
            top: 0;
            height: 100%;
            width: 40%;
            transform: translateX(0);
            transition: transform .6s ease-in-out
        }
        
        .overlay-left {
            transform: translateX(-20%)
        }
        
        .container.right-panel-active .overlay-left {
            transform: translateX(0)
        }
        
        .overlay-right {
            right: 0;
            transform: translateX(0)
        }
        
        .container.right-panel-active .overlay-right {
            transform: translateX(20%)
        }
        /*SLIDING PARAMETERES*/
        
        .container2 {
            background: #fff;
            width: 540px;
            height: 450px;
            margin: 0 auto;
            position: relative;
            margin-top: 10%;
            box-shadow: 2px 5px 20px rgba(119, 119, 119, 0.6);
            left: -550px
        }
        
        .leftbox {
            float: left;
            top: -5%;
            left: 5%;
            position: absolute;
            width: 15%;
            height: 110%;
            background: #3498db;
            box-shadow: 3px 3px 10px rgba(119, 119, 119, 0.5);
            border: .1em solid #fff
        }
        
        .sidee {
            list-style: none;
            padding: 35px;
            color: #fff;
            display: block;
            font-size: 1.1em;
            transition: all .3s ease-in-out
        }
        
        .sidee:hover {
            color: #000626;
            cursor: pointer
        }
        
        .sidee:first-child {
            margin-top: 7px
        }
        
        .rightbox {
            width: 60%;
            margin-left: 27%;
            height: 100px
        }
        
        .profile,
        .settings,
        .notes,
        .action {
            transition: all .5s ease-in;
            position: absolute;
            width: 80%
        }
        
        .rightbox h2 {
            color: #777;
            font-family: "Roboto", sans-serif;
            text-transform: uppercase;
            font-size: 8px;
            letter-spacing: 1px;
            margin-left: 2px;
            margin-top: 10px
        }
        
        .rightbox .input,
        .rightbox p {
            border: 0;
            border-bottom: 1px solid #3fb6a8;
            width: 80%;
            font-family: "Montserrat", sans-serif;
            font-size: .7em;
            padding: 7px 0;
            color: #070707;
            outline: none
        }
        
        span {
            font-size: .7em;
            color: #777
        }
        
        .btn {
            font-family: "Roboto", sans-serif;
            text-transform: uppercase;
            font-size: 15px;
            border: none;
            color: #fff;
            background: #7ed386;
            padding: 7px 15px;
            box-shadow: 0 2px 4px 0 rgba(0, 0, 0, 0.2);
            cursor: pointer;
            margin-top: 15px
        }
        
        .privacy h2,
        .settings h2,
        .notes h2,
        .action h2 {
            margin-top: 25px
        }
        
        .rightbox h1 {
            font-family: "Montserrat", sans-serif;
            color: #7ed386;
            font-size: 1.2rem;
            margin-top: 40px;
            margin-bottom: 35px
        }
        
        .sidebar {
            margin-top: 70px;
            padding-top: 30px;
            position: fixed;
            left: 0;
            width: 250px;
            height: 100%;
            transition: .5s;
            transition-property: left
        }
        
        label #sidebar_btn {
            z-index: 1;
            color: #fff;
            position: fixed;
            cursor: pointer;
            left: 22%;
            font-size: 28px;
            margin: 25px 0;
            transition: .5s;
            transition-property: color
        }
        
        label #sidebar_btn:hover {
            color: #19B3D3
        }
        
        #check:checked~.sidebar {
            left: 523px
        }
        
        #check:checked~.sidebar a span {
            display: none
        }
        
        #check:checked~.content {
            margin-left: 60px
        }
        
        #check {
            display: none
        }
        
        @media screen and (max-width:780px) {
            label #sidebar_btn {
                left: 50%;
                margin-top: 17px
            }
            .action p {
                text-align: left;
                padding-left: 20px;
            }
        }
        
        .sec#blur.active {
            filter: blur(5px)
        }
        /*GRAPHS*/
        
        .graph {
            background-color: rgba(167, 219, 25, 0);
            width: 100%;
            align-items: center;
            box-sizing: border-box
        }
        
        .graph div {
            display: block;
            margin: auto;
            background-color: rgba(14, 14, 14, 0);
            margin-bottom: 3%;
            width: 90%;
            border-radius: 5%
        }
        /*NUMBER INPUT*/
        
        .containernum {
            position: relative;
            width: 60px;
            height: 30px;
            border-radius: 40px;
            border: 2px solid #3498db;
            transition: .5s;
            display: inline-block;
            margin-right: 10%;
            left: -40px;
        }
        
        .containernum:hover {
            width: 120px;
            border: 2px solid #3498db
        }
        
        .containernum .next {
            position: absolute;
            top: 50%;
            right: 30px;
            display: block;
            width: 12px;
            height: 12px;
            border-top: 2px solid #3498db;
            border-left: 2px solid #3498db;
            z-index: 1;
            cursor: pointer;
            opacity: 0;
            transform: translateY(-50%) rotate(135deg);
            transition: .5s
        }
        
        .containernum:hover .next {
            opacity: 1;
            right: 20px
        }
        
        .containernum .prev {
            position: absolute;
            top: 50%;
            left: 30px;
            display: block;
            width: 12px;
            height: 12px;
            border-top: 2px solid #3498db;
            border-left: 2px solid #3498db;
            z-index: 1;
            cursor: pointer;
            opacity: 0;
            transform: translateY(-50%) rotate(315deg);
            transition: .5s
        }
        
        .containernum:hover .prev {
            opacity: 1;
            left: 20px
        }
        
        .containernum span {
            position: relative;
            width: 30%;
            height: 15px;
            margin: auto;
            display: block;
            align-items: center;
            /* display: none;*/
            border: none;
        }
        /* checkbox notifs */
        
        .checkbox {
            position: absolute;
            top: 160px;
            left: 70%;
            transform: translate(-50%, -50%);
        }
        
        .checkbox1 {
            position: absolute;
            top: 246px;
            left: 70%;
            transform: translate(-50%, -50%);
        }
        
        .checkbox2 {
            position: absolute;
            top: 330px;
            left: 70%;
            transform: translate(-50%, -50%);
        }
        
        input[type="checkbox"] {
            position: relative;
            width: 40px;
            height: 20px;
            -webkit-appearance: none;
            background: #c6c6c6;
            outline: none;
            border-radius: 20px;
            box-shadow: inset 0 0 5px rgba(0, 0, 0, 2);
            transition: .5s;
        }
        
        input:checked[type="checkbox"] {
            background: #03a9f4;
        }
        
        input[type="checkbox"]:before {
            content: '';
            position: absolute;
            width: 20px;
            height: 20px;
            border-radius: 20px;
            top: 0;
            left: 0;
            background: white;
            transform: scale(1.1);
            box-shadow: 0 2px 5px;
            transition: .5s;
        }
        
        input:checked[type="checkbox"]:before {
            left: 25px;
        }
        /* check box */
        
        .containernum span input[type="number"] {
            font-size: 15px;
            width: 100%;
            height: 100%;
            text-align: center;
            font-weight: 700;
            margin-top: 6px;
            margin-left: -3px;
            border: none;
            -webkit-appearance: textfield;
            -moz-appearance: textfield;
            appearance: textfield;
        }
        
        input::-webkit-outer-spin-button,
        input::-webkit-inner-spin-button {
            -webkit-appearance: none;
            margin: 0;
        }
        
        #notif1,
        #notif2,
        #notif3 {
            padding-left: 10%;
            display: block;
            height: 40px;
        }
        /*CARDS AND BARS RESPONSIVE*/
        
        @media (max-width: 325px) {
            #blur,
            body {
                padding-left: 20px;
                text-align: center;
                align-content: center;
            }
            .container-card {
                width: 320px;
                padding-left: 30px;
            }
            nav {
                margin-left: -20px
            }
            .times {
                padding-left: 30px;
            }
            .card {
                width: 290px;
            }
            #blur {
                padding-left: 20px;
            }
            #sub {
                font-size: 38px;
            }
        }
        /*accountresponsive*/
        
        @media (max-width: 780px) {
            .rightbox {
                margin-left: 90px;
                width: 40%;
            }
            .container2 {
                width: 320px;
                height: 400px;
            }
            .profile {
                width: 70%;
            }
            .leftbox {
                float: left;
                top: -3%;
                left: 5%;
                width: 20%;
                height: 105%;
            }
            .sidee {
                padding: 22px;
            }
            .containernum {
                width: 50px;
                margin-right: 3%;
            }
            .containernum:hover {
                width: 70px;
            }
            .containernum .next {
                right: 15px;
            }
            .containernum .prev {
                left: 15px;
            }
            .containernum:hover .next {
                right: 10px;
            }
            .containernum:hover .prev {
                left: 10px;
            }
            #notif1,
            #notif2,
            #notif3 {
                padding-left: 0;
            }
            .checkbox,
            .checkbox1,
            .checkbox2 {
                left: 75%;
            }
        }
        
        .tooltiptext {
            visibility: hidden;
            width: 220px;
            background-color: rgb(117, 169, 238);
            color: #fff;
            font-weight: bold;
            text-align: center;
            padding: 4px 0;
            border-radius: 6px;
            position: absolute;
            z-index: 1;
            margin-top: -45px;
        }
        
        .hover:hover .tooltiptext {
            visibility: visible;
            z-index: 9;
            overflow: hidden;
        }
        
        .hover {
            float: left;
            margin-right: 10%;
            left: -40px;
        }
        
        .nav-wrapper {
            position: relative;
            padding-top: 0;
            display: inline-block;
            width: 100%;
        }
        /*alert*/
        
        .alert {
            padding: 13px;
            background-color: #f13312f3;
            color: white;
            width: 80%;
            margin-bottom: 5px;
            margin-left: -10px;
            display: none;
        }
        
        .closebtn2 {
            margin-left: 15px;
            color: white;
            font-weight: bold;
            float: right;
            font-size: 22px;
            line-height: 20px;
            cursor: pointer;
            transition: 0.3s;
        }
        
        .closebtn2:hover {
            color: black;
        }
        
        #lineup {
            display: inline-block;
        }
        
        #not {
            float: left;
        }
        
        #clearall {
            background-color: #ebe9e983;
            border-radius: 50%;
            border: none;
            color: rgba(34, 39, 28, 0.836);
            font-weight: bolder;
            float: left;
            font-size: 15px;
            margin-top: 35px;
            margin-left: 150px;
            padding: 10px;
            cursor: pointer;
        }
        /*NUMBER OF NOTIFS*/
        
        .num {
            position: fixed;
            z-index: 2;
            color: white;
            left: 23%;
            top: 18px;
            background-color: red;
            border-radius: 50%;
            padding-left: 5px;
            padding-right: 5px;
        }
        
        .num1 {
            position: relative;
            z-index: 100000;
            color: white;
            background-color: red;
            border-radius: 50%;
            padding-left: 5px;
            padding-right: 5px;
            margin-left: -10px;
            top: -10px;
        }
        
        #notes {
            margin-top: 30px;
            padding: 0;
            padding-left: 35px;
            display: inline-block;
        }
        
        .allnum {
            display: none;
        }
        
        #counter {
            display: inline-block;
        }
        
        @media (max-width: 780px) {
            #notes {
                padding-left: 5px;
            }
            .num {
                left: 53%;
                margin-top: -5px;
            }
            #clearall {
                margin-top: -63px;
            }
            .alert {
                margin-left: -2px;
                width: 78%;
            }
        }
        
        .closebtn2 {
            margin-left: 15px;
            color: white;
            font-weight: bold;
            float: right;
            font-size: 22px;
            line-height: 20px;
            cursor: pointer;
            transition: 0.3s;
        }
        
        .closebtn2:hover {
            color: black;
        }
        
        .buttonAction {
            background-color: #7ed386;
        }
        
        .buttonAction2 {
            background-color: #77878A;
        }
        
        .checkboxAction {
            margin-left: 280px;
        }
        
        .action tabShow p {
            margin: 0;
        }
        
        #action {
            padding-top: 60px
        }
        /*footer section css*/
        
        footer {
            background: rgba(255, 255, 255, .2);
            padding: 15px;
        }
        
        .footer-container {
            max-width: 1300px;
            margin: 0;
            padding: 0 7% 0 7%;
            padding-top: 0;
            display: flex;
            justify-content: space-between;
            align-items: center;
            flex-wrap: wrap-reverse;
        }
        
        .right-col h1,
        .left-col h1 {
            font-size: 24px;
            color: rgb(255, 255, 255);
            padding-left: 40px;
        }
        
        .border {
            margin-left: 40px;
            margin-top: -5px;
            width: 80px;
            height: 4px;
            background: #e7ba3c;
        }
        
        .newsletter-form {
            display: flex;
            justify-content: center;
            align-items: center;
            flex-wrap: wrap;
            box-sizing: border-box;
        }
        
        .subject,
        .email,
        .message {
            flex: 1;
            padding: 12px 35px;
            font-size: 16px;
            color: #308db8f8;
            background: #fff;
            border: none;
            font-weight: 600;
            outline: none;
            border-radius: 30px;
            max-width: 250px;
            margin: 10px;
            z-index: 99999999;
        }
        
        .subject,
        .email {
            max-width: 150px;
        }
        
        .submit {
            padding: 12px 35px;
            font-size: 16px;
            color: #f1f1f1;
            background: #e7ba3c;
            box-shadow: 2px 2px 1px rgba(0, 0, 0, 0.4);
            border: none;
            font-weight: 700;
            outline: none;
            border-radius: 30px;
            margin-left: 8px;
            cursor: pointer;
            transition: opacity .3s linear;
            margin-top: 0;
            z-index: 999999999
        }
        
        .submit:hover {
            opacity: .8;
        }
        /*animated social media */
        
        .middle {
            position: relative;
            width: 300px;
            margin-top: 0%;
            margin-right: 3%;
            margin-bottom: 2%;
            z-index: 99;
        }
        
        .botn {
            display: inline-block;
            width: 50px;
            height: 50px;
            background: #f1f1f1;
            margin: 7px;
            border-radius: 30%;
            box-shadow: 0 5px 15px -5px #00000070;
            color: #3498db;
            overflow: hidden;
            position: relative;
            text-align: center;
            z-index: 99999999;
        }
        
        .botn i {
            line-height: 50px;
            font-size: 23px;
            transition: .2s linear
        }
        
        .botn:hover i {
            transform: scale(1.3);
            color: #f1f1f1
        }
        
        .botn::before {
            content: "";
            position: absolute;
            width: 120%;
            height: 120%;
            background: #e7ba3c;
            transform: rotate(45deg);
            left: -110%;
            top: 90%
        }
        
        .botn:hover::before {
            animation: aaa .7s 1;
            top: -10%;
            left: -10%
        }
        
        @keyframes aaa {
            0% {
                left: -110%;
                top: 90%
            }
            50% {
                left: 10%;
                top: -30%
            }
            100% {
                top: -10%;
                left: -10%
            }
        }
        
        @media screen and (max-width:960px) {
            .footer-container {
                max-width: 600px;
                margin: auto;
            }
            .right-col {
                width: 100%;
                margin-bottom: 60px;
                text-align: center;
            }
            .left-col {
                width: 100%;
                text-align: center;
            }
            .middle {
                margin-left: 150px
            }
            .checkboxAction {
                margin-left: 45%;
            }
            .action input {
                margin-top: -20px;
            }
            .border {
                margin: auto;
            }
        }
        
        @media screen and (max-width:700px) {
            .middle {
                margin: auto;
            }
        }
        
        @media screen and (max-width:600px) {
            .footer-container {
                max-width: 432px;
                margin: auto;
            }
        }
        
        @media screen and (max-width: 425px) {
            .card {
                margin-left: -12px;
            }
            .base {
                margin-top: 10px
            }
        }
        /*SMALL PHONE RESPONSIVE*/
        
        @media screen and (max-width: 320px) {
            .subject,
            .email,
            .message {
                padding: 16px 10px;
                width: 30px;
                font-size: 12px;
                margin: 5px
            }
            .submit {
                padding: 14px 20px;
                font-size: 12px;
                margin: 5px
            }
            .botn {
                width: 45px;
                height: 45px
            }
            .middle {
                margin-left: -50px;
            }
            footer {
                margin-left: -50px;
            }
            .graph,
            #sub {
                margin-left: -15px
            }
            .card {
                margin-left: -38px
            }
            .condition-bar .temp a {
                font-size: 490%
            }
            .condition-bar div {
                margin: 5px
            }
            .base {
                margin-left: -15px;
            }
        }
    </style>
    <!--firebase config script-->
    <script>
        // Your web app's Firebase configuration
        var firebaseConfig = {
            apiKey: "AIzaSyDiOy4im_2tixIA_fNPtYBA9xhpk9aDgFw",
            authDomain: "arduino-webserver-esisba.firebaseapp.com",
            databaseURL: "https://arduino-webserver-esisba.firebaseio.com",
            projectId: "arduino-webserver-esisba",
            storageBucket: "arduino-webserver-esisba.appspot.com",
            messagingSenderId: "256726388656",
            appId: "1:256726388656:web:16edef465e20447aac1075",
            measurementId: "G-MVDXMGPL6G"
        };
        // Initialize Firebase
        firebase.initializeApp(firebaseConfig);
        // firebase.analytics();
    </script>

    <div class="wrapper">
        <header>
            <nav>
                <!-- SLIDING ACCOUNT PARAMETERS -->
                <input type="checkbox" id="check">
                <div id="sidebarid" class="sidebar">
                    <div class="container2">
                        <div class="leftbox">
                            <a onclick="tabs(0)" id="profile" class="sidee"><i class="fa fa-user"></i></a>
                            <a onclick="tabs(1)" id="payment" class="sidee"><i class="fa fa-cog"></i></a>
                            <div id="counter">
                                <a onclick="tabs(2)" id="notes" class="sidee"> <i class="fa fa-bell"></i> </a>
                                <span class="num1 allnum"></span>
                            </div>
                            <a onclick="tabs(3)" id="action" class="sidee"><i class="fa fa-check-square" ></i></a>
                        </div>
                        <div class="rightbox">
                            <div class="profile tabShow">
                                <h1>Personal Info </h1>
                                <h2>user name</h2>
                                <input id="userNameInputField" type="text" class="input" value="NO USER NAME">
                                <h2>Email</h2>
                                <input id="emailInputField" type="text" class="input" value="example@example.com">
                                <h2>phone number</h2>
                                <input id="phoneNumberInputField" type="text" class="input" value="phone number (+213) ">

                                <h2>Password </h2>
                                <button onclick="resetPassword();" class="input">click here to change your password </button>

                                <button onclick="update_the_acount(); " class="btn-update btn">Update</button>
                            </div>
                            <div class="settings tabShow">
                                <h1>Account Settings</h1>
                                <p>TEMPERATURE </p>
                                <div id="notif1">
                                    <div class="hover ">
                                        <span class="tooltiptext">You'll be notifed when the value gets LOWER than..</span>

                                        <div class="containernum">
                                            <span class="prev" class="addsub"></span>
                                            <span class="next" class="addsub"></span>
                                            <div id="box1">
                                                <span>
                                            <input id="temp-min" type="number"  value="0" max="10">
                                        </span>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="hover ">
                                        <span class="tooltiptext">You'll be notifed when the value gets HIGHER than..</span>

                                        <div class="containernum">
                                            <span class="prev" class="addsub"></span>
                                            <span class="next" class="addsub"></span>
                                            <div id="box2">
                                                <span>
                                            <input id="temp-max" type="number" value="0" min="0">
                                        </span>
                                            </div>
                                        </div>
                                    </div>
                                        <div class="checkbox">
                                            <input type="checkbox" id="checkt">
                                        </div>

                                </div>
                                <p>PRESSURE </p>
                                <div id="notif2">
                                    <div class="hover ">
                                        <span class="tooltiptext">You'll be notifed when the value gets LOWER than..</span>
                                        <div class="containernum">

                                            <span class="prev" class="addsub"></span>
                                            <span class="next" class="addsub"></span>
                                            <div id="box3">
                                                <span>
                                                  <input id="press-min" type="number"  value="0"  max="5">
                                               </span>

                                            </div>

                                        </div>
                                    </div>

                                    <div class="hover ">
                                        <span class="tooltiptext">You'll be notifed when the value gets HIGHER than..</span>

                                        <div class="containernum">
                                            <span class="prev" class="addsub"></span>
                                            <span class="next" class="addsub"></span>
                                            <div id="box4">
                                                <span>
                                            <input id="press-max" type="number" value="0" min="1" max="5">
                                        </span>
                                            </div>
                                        </div>
                                    </div>
                                        <div class="checkbox1">
                                            <input type="checkbox" id="checkp">
                                        </div>
                                    </div>

                                <p>HUMIDITY </p>
                                <div id="notif3">
                                    <div class="hover ">
                                        <span class="tooltiptext">You'll be notifed when the value gets LOWER than..</span>
                                        <div class="containernum">
                                            <span class="prev" class="addsub"></span>
                                            <span class="next" class="addsub"></span>
                                            <div id="box5">
                                                <span>
                                            <input id="humid-min" type="number"  value="0" min="1" max="5">
                                        </span>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="hover ">
                                        <span class="tooltiptext">You'll be notifed when the value gets HIGHER than..</span>

                                        <div class="containernum">
                                            <span class="prev" class="addsub"></span>
                                            <span class="next" class="addsub"></span>
                                            <div id="box6">
                                                <span>
                                            <input id="humid-max" type="number" value="0" min="1" max="5">
                                        </span>
                                            </div>
                                        </div>
                                    </div>
                                        <div class="checkbox2">
                                            <input type="checkbox" id="checkh">
                                        </div>

                                </div>
                                <button onclick="update_the_notif_val(); " class="btn-update btn notifyme">Update</button>
                            </div>
                            <div class="notes tabShow">
                                <div id="lineup">
                                    <h1 id="not">Notifications</h1>
                                    <button id="clearall">clear</button>
                                </div>


                                <div class="alert alert1 low">
                                    <span class="closebtn2" onclick="this.parentElement.style.display=''; ">&times;</span>
                                    <strong>TEMPERATURE : </strong> The value is too LOW !

                                </div>
                                <div class="alert alert2 high">
                                    <span class="closebtn2" onclick="this.parentElement.style.display='none'; ">&times;</span>
                                    <strong>TEMPERATURE : </strong> The value is too HIGH !

                                </div>
                                <div class="alert alert3 low">
                                    <span class="closebtn2" onclick="this.parentElement.style.display='none'; ">&times;</span>
                                    <strong>PRESSURE :</strong> The value is too LOW !
                                </div>
                                <div class="alert alert4 high">
                                    <span class="closebtn2" onclick="this.parentElement.style.display='none'; ">&times;</span>
                                    <strong>PRESSURE: </strong> The value is too HIGH !
                                </div>
                                <div class="alert alert5 low">
                                    <span class="closebtn2" onclick="this.parentElement.style.display='none'; ">&times;</span>
                                    <strong>HUMIDITY!</strong>The value is too LOW !
                                </div>
                                <div class="alert alert6 high">
                                    <span class="closebtn2" onclick="this.parentElement.style.display='none'; ">&times;</span>
                                    <strong>HUMIDITY!</strong>The value is too HIGH !
                                </div>

                            </div>

                            <div class="action tabShow">
                                <h1> Actions</h1>
                                <p>L E D</p>
                                <div class="checkboxAction">
                                    <input type="checkbox" id="checkaction" onclick="alifunction()" name="">
                                </div>
                                <p>Moteur d'action</p>
                                <div class="checkboxAction">
                                    <input type="checkbox"id="checkaction1" onclick="alifunction1()" name="">
                                </div>
                                <p>L E D 2</p>
                                <div class="checkboxAction">
                                    <input type="checkbox"id="checkaction2" onclick="alifunction2()" name="">
                                </div>
                                <p>Moteur d'action 2</p>
                                <div class="checkboxAction">
                                    <input type="checkbox"id="checkaction3" onclick="alifunction3()" name="">
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
                <!-- MENU BAR  -->
                <div class="menu-icon">
                    <i class="fa fa-bars fa-2x"></i>
                </div>
                <div class="logo">
                    <img alt="logo" src="https://i.ibb.co/Yfxw86F/logo1.png" id="logoimg">
                </div>
                <label for="check">
                    <i class="fas fa-user-circle" id="sidebar_btn" onclick="toggle()"></i>

             </label>
                <span class="num allnum">  </span>
                <div class="nav-wrapper">
                    <div class="menu">
                        <ul>

                            <li><a href="#" onclick="logout()" id="logout_butt">Logout</a></li>
                            <li><a href="#" id="button1" class="button1">Sign In</a></li>
                            <li><a href="#graph">Graphs</a></li>
                            <li><a href="#forcast">Forcast</a></li>
                            <li><a href="/report" id="report" onclick="goToReportPage()" role="button">Report</a></li>

                        </ul>
                    </div>
                </div>
            </nav>
        </header>
    </div>
    <!-- HIDING MENU -->
    <script type="text/javascript">
        $(document).ready(function() {
            $(".menu-icon").on("click", function() {
                $(".menu").toggleClass("showing");
                $(".menu").toggleClass("menu2");


            });
        });
        // code of scroll animation
        $(window).on("scroll", function() {
            if ($(window).scrollTop()) {
                $('nav').addClass('black');
            } else {
                $('nav').removeClass('black');
            }
        });
        //CLEARALL NOTIFS
        $(document).ready(function() {
            $("#clearall").click(function() {
                $(".alert").hide(200);
            });
        });
    </script>
    <div class="sec" id="blur">
        <!-- this is base :condition-bar + times bar -->
        <div class="base">
            <div class="condition-bar">
                <div class="cb1">
                    <div class="cond-img">
                        <a><img src="https://i.ibb.co/3rBxJxY/sun.png" width="120px" height="120px" id="condimg"></a>
                    </div>
                    <div class="temp">
                        <a id="temperature">--</a><a>&#730;</a>
                    </div>
                </div>
                <div class="cb2">
                    <div class="block1">
                        <div class="chor">
                            <i class="fas fa-cloud-showers-heavy" aria-hidden="true"></i>
                            <a id="water"> --</a><a> mm</a>
                        </div>
                        <div class="humid">
                            <i class="fa fa-tint" aria-hidden="true"></i>
                            <a id="humidity"> --</a><a> &#37;</a>
                        </div>
                    </div>
                    <div class="block2">
                        <div class="press">
                            <i class="fa fa-tachometer" aria-hidden="true"></i>
                            <a id="pressure"> -- </a><a> hPa</a>
                        </div>
                        <div class="wind">
                            <i class="fas fa-wind" aria-hidden="true"></i>
                            <a id="wind"> --</a><a> Km/h</a>
                        </div>
                    </div>
                </div>
            </div>
            <div class="times">
                <div class=" date"><i class="fa fa-calendar" aria-hidden="true"></i>
                    <a id="date" style="font-size:1.0rem;"> </a>
                </div>
                <div class="time"><i class="fa fa-clock-o" aria-hidden="true"></i>
                    <a id="time"> </a>
                </div>
                <div class="sunrise">
                    <a><img src="https://i.ibb.co/r3XmRDB/sunrise.png" height="30px" width="30px"> 07:05 AM</a>
                </div>
                <div class="sunset">
                    <a><img src="https://i.ibb.co/TPXf1kD/sunset.png" height="30px" width="30px"> 06:32 PM</a>
                </div>

            </div>
            <a id="forcast"></a>
        </div>

        <!--  this is beggining of 2 card sets -->

        <div id="sub"> S E N S O R S </div>
        <div class="container-card">
            <div class="card">
                <div class="card-content">
                    <div class="front"><i class="fa fa-thermometer-quarter" aria-hidden="true"></i>
                        <h3>Temp</h3>
                    </div>
                    <div class="back">
                        <a class="realinfo1">
                            <p id="temperature1">temp
                                <p>&#8451</p>
                            </p>
                            <p id="temperatureF">temp
                                <p>&#8457</p>
                            </p>
                        </a><a class="viewgraph" href="#graf1"> View Graph</a></div>
                </div>
            </div>
            <div class="card">
                <div class="card-content">
                    <div class="front"><i class="fas fa-tint" aria-hidden="true"></i>
                        <h3>Humidity</h3>
                    </div>
                    <div class="back">
                        <a class="realinfo1">
                            <p id="humidity1">humid</p>
                            <p id="dewpoint">dewpoint</p>
                        </a><a class="viewgraph" href="#graf2"> View Graph</a></div>
                </div>
            </div>
            <div class="card">
                <div class="card-content">
                    <div class="front"><i class="fas fa-cloud-showers-heavy"></i>
                        <h3>Rain</h3>
                    </div>
                    <div class="back">
                        <a class="realinfo1">
                            <p id="rain">rain</p>
                            <p id="water1">water</p><p>mm</p>
                        </a><a class="viewgraph" href="#graf4"> View Graph</a></div>
                </div>
            </div>

            <div class="card">
                <div class="card-content">
                    <div class="front"><i class="fas fa-wind"></i>
                        <h3>Wind</h3>
                    </div>
                    <div class="back"><a class="realinfo" ><p id="wind1">wind</p></a>
                        <a class="viewgraph" href="#graf5"> View Graph</a></div>
                </div>
            </div>
            <div class="card">
                <div class="card-content">
                    <div class="front"><i class="fa fa-tachometer" aria-hidden="true"></i>
                        <h3>Pressure</h3>
                    </div>
                    <div class="back">
                        <a class="realinfo" ><p  id="pressure1"> press</p></p></a>
                        <a class="viewgraph" href="#graf3"> View Graph</a></div>
                </div>
            </div>
            <div class="card">
                <div class="card-content">
                    <div class="front"><i class="fas fa-sun-o"></i>
                        <h3>Solar</h3>
                    </div>
                    <div class="back">
                        <a class="realinfo" id="informations">info </a>
                        
                    </div>
                </div>
            </div>
            <a name="graph"></a>
        </div>

        <!-- graph section -->
        <p id="sub"> G R A P H S
        </p>
        <div class="graph" id="graf1">
            <br><br>
            <div id="cont1">
                <div id="chart-temperature"> </div>
            </div>
            <p id="graf2"></p>
            <br><br>
            <div id="cont2">
                <div id="chart-humidity"></div>
            </div>
            <p id="graf3"></p>
            <br><br>
            <div id="cont3">
                <div id="chart-pressure"></div>
            </div>
            <p id="graf4"></p>
            <br><br>
            <div id="cont4">
                <div id="chart-rain"></div>
            </div>
            <p id="graf5"></p>
            <br><br>
            <div id="cont5">
                <div id="chart-wind"></div>
            </div>
            <!--<script src="chart.js"></script>-->
        </div>


        <!-- comment and footer section -->
        <footer>
            <div class="footer-container">
                <div class="right-col">
                    <h1>Leave Us a Comment</h1>
                    <div class="border"></div>
                    <form action="https://formspree.io/esisbameteo@gmail.com" method="POST">
                        <div class="newsletter-form">
                            <input type="text" name="subject" class="subject" placeholder="Enter Subject">
                            <input type="email" name="email" class="email" placeholder="Enter Your Email">
                        </div>
                        <div class="newsletter-form">
                            <input type="text" name="message" class="message" placeholder="Enter Your Message">
                            <div class="status"></div>
                            <input type="submit" class="submit" value="submit">
                        </div>
                    </form>
                </div>
                <div class="left-col">
                    <h1>Contact Us</h1>
                    <div class="border"></div>
                    <br>
                    <div class="middle">
                        <a class="botn" target="_blank" href="https://web.facebook.com/Esi-Weather-Station-103928668045571/">
                            <i class="fab fa-facebook-f"></i>
                        </a>
                        <a class="botn" target="_blank" href=" https://twitter.com/EsiWeather">
                            <i class="fab fa-twitter"></i>
                        </a>
                        <a class="botn" target="_blank" href="https://www.youtube.com/channel/UCpCga5y_Mb_x77RkEcIv2Iw?view_as=subscriber">
                            <i class="fab fa-youtube"></i>
                        </a>
                        <a class="botn" target="_blank" href="https://www.instagram.com/esi.station/?hl=fr">
                            <i class="fab fa-instagram"></i>
                        </a>
                    </div>
                </div>


            </div>
        </footer>
        <script>
            // SEND A COMMENT
            console.log('It works')

            $(document).ready(function() {
                $('.submit').click(function(event) {
                    console.log('Clicked button')

                    var email = $('.email').val()
                    var subject = $('.subject').val()
                    var message = $('.message').val()
                    var statusElm = $('.status')
                    statusElm.empty()

                    if (email.length > 5 && email.includes('@') && email.includes('.')) {
                        statusElm.append('<div>Email is valid</div>')
                    } else {
                        statusElm.append('<div>Email is not valid</div>')
                    }

                    if (subject.length >= 2) {
                        statusElm.append('<div>Subject is valid</div>')
                    } else {
                        statusElm.append('<div>Subject is not valid</div>')
                    }

                    if (message.length > 10) {
                        statusElm.append('<div>Message is valid</div>')
                    } else {
                        statusElm.append('<div>Message is not valid</div>')
                    }

                })

            })
        </script>
        <!-- pop up modal FOR SIGNUP-IN section  -->
        <div class="bg-modal">
            <div class="modal-content">
                <div id="close" class="close"><a href="#">+</a></div>
                <div class="container" id="container">
                    <div class="form-container sign-up-container">
                        <form action="#">
                            <h1>Create Account</h1>
                            <input type="text" placeholder="User Name" id="user_name_field" />
                            <input type="tel" placeholder="Phone Nember (+213)" id="phone_number_field" />
                            <input type="email" placeholder="Email" id="email2_field" />
                            <input type="password" placeholder="Password" id="password2_field" />
                            <button onclick="signUp()">Sign Up</button>
                        </form>
                    </div>
                    <div class="form-container sign-in-container">
                        <form>
                            <h1>Sign in</h1>
                            <input type="email" placeholder="Email" id="email_field" />
                            <input type="password" placeholder="Password" id="password_field" />
                            <button onclick="login()">Sign In</button>
                        </form>
                    </div>
                    <div class="overlay-container">
                        <div class="overlay">
                            <div class="overlay-panel overlay-left">
                                <h1>Welcome Back!</h1>
                                <p>To keep connected with us please login with your personal info</p>
                                <button class="ghost" id="signIn">Sign In</button>
                            </div>
                            <div class="overlay-panel overlay-right">
                                <h1>Hello, Friend!</h1>
                                <p>Enter your personal details and start journey with us</p>
                                <button class="ghost" id="signUp">Sign Up</button>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <!-- pop up modal script  -->
        <script type="text/javascript">
            document.getElementById('button1').addEventListener("click", function() {
                document.querySelector('.bg-modal').style.display = "flex";
                document.body.style.overflow = "hidden";
                document.querySelector('nav ul').style.display = "none";
            });


            document.querySelector('.close').addEventListener("click", function() {
                document.querySelector('.bg-modal').style.display = "none";
                document.body.style.overflow = "auto";
                document.querySelector('nav ul').style.display = "block";
            });
        </script>
        <!-- form slide script -->
        <!--<script src="login.js"></script>-->
        <!--   js for realtime sensor values is included  -->
        <!--<script src="side.js"></script>-->


    </div>
    </div>
    <script>
        //INTIALIZE INFORMATIONS+HIDE OR SHOW ELEMENTS IF SIGNEDIN
        const signUpButton = document.getElementById('signUp');
        const signInButton = document.getElementById('signIn');
        const container = document.getElementById('container');

        signUpButton.addEventListener('click', () => {
            container.classList.add("right-panel-active");
        });

        signInButton.addEventListener('click', () => {
            container.classList.remove("right-panel-active");
        });


        var mintemp, maxtemp, minhumi, maxhumi, mipress, maxpress, checkt, checkh, checkp;
 function alifunction() {
                        var checkaction;
                        
                        if (document.getElementById('checkaction').checked) {
                            checkaction = "ON";
                        } else {
                            checkaction = "OFF";
                        }

                        firebase.database().ref('/actions/action1/').set({
                                name: "LED1",
                                state: checkaction
                            },
                            function(error) {
                                if (error) {
                                    window.alert("The write failed...");

                                    window.alert(error.message);
                                }
                            })
                    };


                    function alifunction1() {
                        var checkaction1;
                        if (document.getElementById('checkaction1').checked) {
                            checkaction1 = "ON";
                        } else {
                            checkaction1 = "OFF";
                        }

                        firebase.database().ref('/actions/action2/').set({
                                name: "Moteur d'action",
                                state: checkaction1
                            },
                            function(error) {
                                if (error) {
                                    window.alert("The write failed...");

                                    window.alert(error.message);
                                }
                            })
                    };


                    function alifunction2() {
                        var checkaction3;
                        if (document.getElementById('checkaction2').checked) {
                            checkaction3 = "ON";
                        } else {
                            checkaction3 = "OFF";
                        }

                        firebase.database().ref('/actions/action3').set({
                                name: "LED2",
                                state: checkaction3
                            },
                            function(error) {
                                if (error) {
                                    window.alert("The write failed...");

                                    window.alert(error.message);
                                }
                            })


                            
                            
                    };




                    function alifunction3() {
                        var checkaction4;
                        if (document.getElementById('checkaction3').checked) {
                            checkaction4 = "ON";
                        } else {
                            checkaction4 = "OFF";
                        }

                        firebase.database().ref('/actions/action4/').set({
                                name: "Moteur d'action2",
                                state: checkaction4
                            },
                            function(error) {
                                if (error) {
                                    window.alert("The write failed...");

                                    window.alert(error.message);
                                }
                            })

                    };

                                        //ADDED
        firebase.database().ref('/icons').on('value', function(snapshot) {
            let x = snapshot.val();
            if (x.weather == "rain") {
                document.getElementById("condimg").src = "https://i.ibb.co/3fNVhnz/rainy.png"
                document.getElementById("informations").innerHTML = "\n It's raining"
            } else if (x.weather == "sun") {
                document.getElementById("condimg").src = "https://i.ibb.co/wYSN9r1/sunny.png"
                document.getElementById("informations").innerHTML = "\n It's sunny"
            } else if (x.weather == "cloud") {
                document.getElementById("condimg").src = "https://i.ibb.co/cv6PrMR/cloudy.png"
                document.getElementById("informations").innerHTML = "\n It's cloudy"
            } else {
                document.getElementById("condimg").src = "https://i.ibb.co/h8MsPdz/snowy.png"
                document.getElementById("informations").innerHTML = "\n It's snowing"
            }
        });

        firebase.auth().onAuthStateChanged(function(user) {
            if (user) {

               


                var user = firebase.auth().currentUser;
                //window.alert(firebase.database().ref().child("users").push().key);

                if (user.emailVerified) {
                    //window.alert("user = true + desplay begin " );
                    document.getElementById("button1").style.display = "none";
                    document.querySelector('.bg-modal').style.display = "none";
                    document.getElementById("logout_butt").style.display = "block";
                    document.getElementById("sidebar_btn").style.display = "inline";
                    document.getElementById("report").style.display = "inline";
                    document.querySelector('nav ul').style.display = "inline";
                    document.body.style.overflow = "auto";
                    document.getElementById("sidebarid").style.display = "inline";
                    // document.getElementById("blur").style.display = "inline";

                    var userId = firebase.auth().currentUser.uid;

                    return firebase.database().ref('/users/').on('value', gotData, errData);

                    function gotData(data) {
                        let x = data.val();


                       
                        var val = firebase.database().ref('/actions/action1/');
                    val.on('value', function(snapshot) {
                        let x = snapshot.val();
                        
                        
                        if (x.state == "ON") {
                            document.getElementById('checkaction').checked = true;
                        } else {
                            document.getElementById('checkaction').checked = false;
                        }

                    });


                    var val2 = firebase.database().ref('/actions/action2/');
                    val2.on('value', function(snapshot) {
                        let x2 = snapshot.val();
                        if (x2.state == "ON") {
                            document.getElementById('checkaction1').checked = true;
                        } else {
                            document.getElementById('checkaction1').checked = false;
                        }
                    });
                    var val3 = firebase.database().ref('/actions/action3/');
                    val3.on('value', function(snapshot) {
                        let x3 = snapshot.val();
                        if (x3.state == "ON") {
                            document.getElementById('checkaction2').checked = true;
                        } else {
                            document.getElementById('checkaction2').checked = false;
                        }
                    });
                    var val4 = firebase.database().ref('/actions/action4/');
                    val4.on('value', function(snapshot) {
                        let x4 = snapshot.val();
                        if (x4.state == "ON") {
                            document.getElementById('checkaction3').checked = true;
                        } else {
                            document.getElementById('checkaction3').checked = false;
                        }
                    });








                        document.getElementById("userNameInputField").value = x[userId].username || 'Anonymous';
                        document.getElementById("emailInputField").value = user.email;
                        document.getElementById("phoneNumberInputField").value = x[userId].phone_number || 'No phone number';
                        document.getElementById("temp-min").value = x[userId].notif.temperature_valeur_min || '0';
                        document.getElementById("temp-max").value = x[userId].notif.temperature_valeur_max || '0';
                        document.getElementById("press-min").value = x[userId].notif.pressure_valeur_min || '0';
                        document.getElementById("press-max").value = x[userId].notif.pressure_valeur_max || '0';
                        document.getElementById("humid-min").value = x[userId].notif.humidity_valeur_min || '0';
                        document.getElementById("humid-max").value = x[userId].notif.humidity_valeur_max || '0';
                        //NOTIFS COUNTING
                        if (x[userId].notif.temp_checkbox == "1") {
                            document.getElementById('checkt').checked = true;
                        } else {
                            document.getElementById('checkt').checked = false;
                        }
                        checkt = x[userId].notif.temp_checkbox;
                        if (x[userId].notif.hum_checkbox == "1") {
                            document.getElementById('checkh').checked = true;

                        } else {
                            document.getElementById('checkh').checked = false;

                        }

                        checkh = x[userId].notif.hum_checkbox;

                        if (x[userId].notif.press_checkbox == "1") {
                            document.getElementById('checkp').checked = true;

                        } else {
                            document.getElementById('checkp').checked = false;

                        }
                        checkp = x[userId].notif.press_checkbox;

                        mintemp = x[userId].notif.temperature_valeur_min || '0';
                        maxtemp = x[userId].notif.temperature_valeur_max || '0';
                        minpress = x[userId].notif.pressure_valeur_min || '0';
                        maxpress = x[userId].notif.pressure_valeur_max || '0';
                        minhumi = x[userId].notif.humidity_valeur_min || '0';
                        maxhumi = x[userId].notif.humidity_valeur_max || '0';



                        




                    };

                    function errData(err) {
                        console.log(err);
                        alert('error!!');
                    };

                    //document.getElementById("").value= ;
                    //window.alert("user = true + desplay end" );
                    //         document.getElementById("verif").style.display = "none";
                    //ADDED
                   
                    
                    
                 /*   document.getElementById('checkaction').addEventListener("click",function() {
                        var checkaction;
                        
                        if (document.getElementById('checkaction').checked) {
                            checkaction = "ON";
                        } else {
                            checkaction = "OFF";
                        }

                        firebase.database().ref('/actions/action1/').set({
                                name: "LED1",
                                state: checkaction
                            },
                            function(error) {
                                if (error) {
                                    window.alert("The write failed...");

                                    window.alert(error.message);
                                }
                            })});*/

/*
                    setInterval(function() {
                        var checkaction;
                        
                        if (document.getElementById('checkaction').checked) {
                            checkaction = "ON";
                        } else {
                            checkaction = "OFF";
                        }

                        firebase.database().ref('/actions/action1/').set({
                                name: "LED1",
                                state: checkaction
                            },
                            function(error) {
                                if (error) {
                                    window.alert("The write failed...");

                                    window.alert(error.message);
                                }
                            })

                            var checkaction1;
                        if (document.getElementById('checkaction1').checked) {
                            checkaction1 = "ON";
                        } else {
                            checkaction1 = "OFF";
                        }

                        firebase.database().ref('/actions/action2/').set({
                                name: "Moteur d'action",
                                state: checkaction1
                            },
                            function(error) {
                                if (error) {
                                    window.alert("The write failed...");

                                    window.alert(error.message);
                                }
                            })

                            var checkaction3;
                        if (document.getElementById('checkaction2').checked) {
                            checkaction3 = "ON";
                        } else {
                            checkaction3 = "OFF";
                        }

                        firebase.database().ref('/actions/action3').set({
                                name: "LED2",
                                state: checkaction3
                            },
                            function(error) {
                                if (error) {
                                    window.alert("The write failed...");

                                    window.alert(error.message);
                                }
                            })


                            var checkaction4;
                        if (document.getElementById('checkaction3').checked) {
                            checkaction4 = "ON";
                        } else {
                            checkaction4 = "OFF";
                        }

                        firebase.database().ref('/actions/action4/').set({
                                name: "Moteur d'action2",
                                state: checkaction4
                            },
                            function(error) {
                                if (error) {
                                    window.alert("The write failed...");

                                    window.alert(error.message);
                                }
                            })


                    }, 1000);
                   
*/


                } else {

                    //window.alert("verif = false");
                    window.alert("the axxunt is not verify");
                    window.alert("please check your email to verify the registration");
                    document.getElementById("logout_butt").style.display = "none";
                    document.getElementsByClassName("num1").style.display = "none";
                    document.getElementById("sidebar_btn").style.display = "none";
                    document.getElementById("button1").style.display = "inline";
                    document.getElementById("report").style.display = "none";
                    document.querySelector('nav ul').style.display = "inline";
                    document.body.style.overflow = "auto";
                    //document.getElementById("verif").style.display = "inline";

                }

                if (user != null) {

                    let email_id = user.email;
                    // document.getElementById("user_para").innerHTML = "Welcome User : " + email_id;
                    window.alert("Welcome User : " + email_id);
                }

            } else {
                document.getElementById("logout_butt").style.display = "none";
                document.getElementById("sidebar_btn").style.display = "none";
                //document.getElementsByClassName("num1").style.display = "none";
                document.getElementById("button1").style.display = "inline";
                document.getElementById("report").style.display = "none";
                document.querySelector('nav ul').style.display = "inline";
                document.body.style.overflow = "auto";
                document.getElementById("sidebarid").style.display = "none";
                document.getElementsByClassName("allnum").style.display = "none";
                // document.getElementById("blur").style.display = "none";
                document.getElementsByClassName("allnum").style.display = "none";


                //  document.getElementById("body1").style.display = "inline";

            }
        });

        //funtions here


        function signUp() {

            var user2Email = document.getElementById("email2_field").value;
            var user2Pass = document.getElementById("password2_field").value;
            var userName = document.getElementById("user_name_field").value;
            var phoneNumber = document.getElementById("phone_number_field").value;
            var tempMin = document.getElementById("temp-min").value.toString();
            var tempMax = document.getElementById("temp-max").value.toString();
            var pressMin = document.getElementById("press-min").value.toString();
            var pressMax = document.getElementById("press-max").value.toString();
            var humidMin = document.getElementById("humid-min").value.toString();
            var humidMax = document.getElementById("humid-max").value.toString();
            var kk = "0";
            firebase.auth().createUserWithEmailAndPassword(user2Email, user2Pass).then(function(response) {


                var user = firebase.auth().currentUser;

                firebase.database().ref('users/' + firebase.auth().currentUser.uid + "/").set({
                    username: userName,
                    email: user2Email,
                    phone_number: phoneNumber
                });
                firebase.database().ref('users/' + firebase.auth().currentUser.uid + "/" + 'notif/').set({
                    temperature_valeur_max: tempMax,
                    temperature_valeur_min: tempMin,
                    humidity_valeur_max: humidMax,
                    humidity_valeur_min: humidMin,
                    pressure_valeur_max: pressMax,
                    pressure_valeur_min: pressMin,
                    temp_checkbox: kk,
                    hum_checkbox: kk,
                    press_checkbox: kk

                });

                user.sendEmailVerification().then(function() { /* Email sent.*/
                    window.alert("check your email ");
                }).catch(function(error) { /* An error happened.*/
                    window.alert("Error : " + error.message);
                });

            }).catch(function(error) {
                // Handle Errors here.
                var errorCode = error.code;
                let errorMessage = error.message;

                window.alert("Error : " + errorMessage);

                // ...
            });

        }

        function login() {

            var userEmail = document.getElementById("email_field").value;
            var userPass = document.getElementById("password_field").value;

            firebase.auth().signInWithEmailAndPassword(userEmail, userPass).catch(function(error) {
                // Handle Errors here.
                var errorCode = error.code;
                let errorMessage = error.message;

                window.alert("Error : " + errorMessage);

                // ...
            });


        }

        function logout() {


            var user = firebase.auth().currentUser;
            if (user != null) {

                let email_id = user.email;
                alert("goodbye User : " + email_id);
            }
            document.getElementById('blur').classList.remove('active');




            firebase.auth().signOut();

        }

        function goToReportPage() {
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET", "/report", true);
            xhttp.send();
        }


        function update_the_acount() {
            var user2Email = document.getElementById("emailInputField").value;
            var userName = document.getElementById("userNameInputField").value;
            var phoneNumber = document.getElementById("phoneNumberInputField").value;
            //window.alert(firebase.database().ref().child("users/"+firebase.auth().currentUser.uid).push().key);

            firebase.database().ref('users/' + firebase.auth().currentUser.uid + "/").set({
                username: userName,
                email: user2Email,
                phone_number: phoneNumber
            }, function(error) {
                if (error) {
                    window.alert("The write failed...");

                    window.alert(error.message);
                } else {
                    window.alert("Data saved successfully!");
                }
            });
        }

        function resetPassword() {

            var auth = firebase.auth();
            var emailAddress = firebase.auth().currentUser.email;

            auth.sendPasswordResetEmail(emailAddress).then(function() {
                // Email sent.
                window.alert("check your email ");
            }).catch(function(error) {
                // An error happened.
                window.alert("error! : " + error.message)
            });

        }

        function update_the_notif_val() {
            var temp_checkbox = 0;
            var hum_checkbox = 0;
            var press_checkbox = 0;
            var tempMin = document.getElementById("temp-min").value.toString();
            var tempMax = document.getElementById("temp-max").value.toString();
            var pressMin = document.getElementById("press-min").value.toString();
            var pressMax = document.getElementById("press-max").value.toString();
            var humidMin = document.getElementById("humid-min").value.toString();
            var humidMax = document.getElementById("humid-max").value.toString();
            if (document.getElementById('checkt').checked) {
                temp_checkbox = 1;
            } else {
                temp_checkbox = 0;
            }



            if (document.getElementById('checkh').checked) {
                hum_checkbox = 1;
            } else {
                hum_checkbox = 0;
            }



            if (document.getElementById('checkp').checked) {
                press_checkbox = 1;
            } else {
                press_checkbox = 0;
            }

            firebase.database().ref('users/' + firebase.auth().currentUser.uid + "/" + 'notif/').set({
                temperature_valeur_max: tempMax,
                temperature_valeur_min: tempMin,
                humidity_valeur_max: humidMax,
                humidity_valeur_min: humidMin,
                pressure_valeur_max: pressMax,
                pressure_valeur_min: pressMin,
                temp_checkbox: temp_checkbox,
                hum_checkbox: hum_checkbox,
                press_checkbox: press_checkbox

            }, function(error) {
                if (error) {
                    window.alert("The write failed...");

                    window.alert(error.message);
                } else {
                    window.alert("Data saved successfully!");
                }
            });

        }


        // code for realtime sensor values
        /*
        setInterval(function ( ) {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                document.getElementById("whater_lavel").innerHTML = this.responseText;
                }
            };

            xhttp.open("GET", "/whater_lavel", true);
            xhttp.send();
            }, 10000 ) ;
        */
        setInterval(function() {
            var t = new Date();
            document.getElementById("time").innerHTML = t.toLocaleTimeString();
            var d = new Date();
            const dayNames = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
            const monthNames = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
            document.getElementById("date").innerHTML = dayNames[d.getDay()] + ", " + d.getDate() + "-" + monthNames[d.getMonth()] + "-" + d.getFullYear();
        }, 1000);
        


        var realtemp, realhumi, realpress

        setInterval(function() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    let x;
                    realtemp = this.responseText;

                    x = this.responseText;

                    document.getElementById("temperature").innerHTML = x;
                    document.getElementById("temperature1").innerHTML = x;

                }
            };
            xhttp.open("GET", "/temperature", true);
            xhttp.send();
        }, 10000);

        setInterval(function() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {

                    document.getElementById("temperatureF").innerHTML = this.responseText;
                }
            };
            xhttp.open("GET", "/temperatureF", true);
            xhttp.send();
        }, 10000);

        setInterval(function() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    let x;
                    realpress = this.responseText;
                    x = this.responseText;
                    document.getElementById("pressure").innerHTML = x;
                    document.getElementById("pressure1").innerHTML = x + " hPa";
                    document.getElementById("pressure1").style.textAlign = "center";

                }
            };
            xhttp.open("GET", "/pressure", true);
            xhttp.send();
        }, 10000);

        setInterval(function() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    let x;
                    realhumi = this.responseText;
                    x = this.responseText;
                    document.getElementById("humidity").innerHTML = x;
                    document.getElementById("humidity1").innerHTML = x + " %";

                }
            };
            xhttp.open("GET", "/humidity", true);
            xhttp.send();
        }, 10000);

        setInterval(function() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    let x;
                    x = this.responseText;
                    document.getElementById("rain").innerHTML = x;
                }
            };
            xhttp.open("GET", "/rain", true);
            xhttp.send();
        }, 10000);

        setInterval(function() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    let x;
                    x = this.responseText;
                    document.getElementById("wind").innerHTML = x;
                    document.getElementById("wind1").innerHTML = x + " Km/h";
                    document.getElementById("wind1").style.textAlign = "center";

                }
            };
            xhttp.open("GET", "/wind", true);
            xhttp.send();
        }, 10000);

        setInterval(function() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    let x;
                    x = this.responseText;
                    document.getElementById("water").innerHTML = x;
                    document.getElementById("water1").innerHTML = x;

                }
            };
            xhttp.open("GET", "/water_level", true);
            xhttp.send();
        }, 10000);

        setInterval(function() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    let x;
                    x = this.responseText;
                    document.getElementById("dewpoint").innerHTML = x;
                    document.getElementById("dewpoint1").innerHTML = " DP " + x;

                }
            };
            xhttp.open("GET", "/dew_point", true);
            xhttp.send();
        }, 10000);
        /*
            setInterval(function ( ) {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                document.getElementById("point_de_rose").innerHTML = this.responseText;
                }
            };
            xhttp.open("GET", "/point_de_rose", true);
            xhttp.send();
            }, 10000 ) ;*/
    </script>

    <script>
        const tabBtn = document.querySelectorAll(".sidee");
        const tab = document.querySelectorAll(".tabShow");

        function tabs(panelIndex) {
            tab.forEach(function(node) {
                node.style.display = "none";
            });
            tab[panelIndex].style.display = "block";
        }

        tabs(0);

        $(".sidee").click(function() {
            $(this).addClass("active").siblings().removeClass("active");
        });

        /*graphs*/
        var chartT = new Highcharts.Chart({
            chart: {
                renderTo: 'chart-temperature',
                backgroundColor: "rgba(255, 255, 255, 0.3)",
                height: 'inherit',
            },
            title: {
                text: ' Temperature'
            },
            series: [{
                name: 'T',
                showInLegend: false,
                data: []
            }],
            plotOptions: {
                line: {
                    animation: false,
                    dataLabels: {
                        enabled: true
                    }
                },
                series: {
                    color: '#059e8a'
                }
            },

            xAxis: {
                type: 'datetime',
                dateTimeLabelFormats: {
                    second: '%H:%M:%S'
                }
            },

            yAxis: {
                title: {
                    text: 'Temperature (Celsius)'
                }
                //title: { text: 'Temperature (Fahrenheit)' }
            },
            credits: {
                enabled: false
            }
        });
        setInterval(function() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    var x = (new Date()).getTime(),
                        y = parseFloat(this.responseText);
                    //console.log(this.responseText);
                    if (chartT.series[0].data.length > 40) {
                        chartT.series[0].addPoint([x, y], true, true, true);
                    } else {
                        chartT.series[0].addPoint([x, y], true, false, true);
                    }
                }
            };
            xhttp.open("GET", "/temperature", true);
            xhttp.send();
        }, 10000);

        var chartH = new Highcharts.Chart({
            chart: {
                renderTo: 'chart-humidity',
                backgroundColor: "rgba(255, 255, 255, 0.3)",
                height: 'inherit',
            },
            title: {
                text: 'BME280 Humidity'
            },
            series: [{
                showInLegend: false,
                data: []
            }],
            plotOptions: {
                line: {
                    animation: false,
                    dataLabels: {
                        enabled: true
                    }
                },
                series: {
                    color: '#555577'
                }
            },
            xAxis: {
                type: 'datetime',
                dateTimeLabelFormats: {
                    second: '%H:%M:%S'
                }
            },
            yAxis: {
                title: {
                    text: 'Humidity (%)'
                }
            },
            credits: {
                enabled: false
            }
        });
        setInterval(function() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    var x = (new Date()).getTime(),
                        y = parseFloat(this.responseText);
                    //console.log(this.responseText);
                    if (chartH.series[0].data.length > 40) {
                        chartH.series[0].addPoint([x, y], true, true, true);
                    } else {
                        chartH.series[0].addPoint([x, y], true, false, true);
                    }
                }
            };
            xhttp.open("GET", "/humidity", true);
            xhttp.send();
        }, 10000);

        var chartP = new Highcharts.Chart({
            chart: {
                renderTo: 'chart-pressure',
                backgroundColor: "rgba(255, 255, 255, 0.3)",
                height: 'inherit',
            },
            title: {
                text: 'BME280 Pressure'
            },
            series: [{
                showInLegend: false,
                data: []
            }],
            plotOptions: {
                line: {
                    animation: false,
                    dataLabels: {
                        enabled: true
                    }
                },
                series: {
                    color: '#18009c'
                }
            },
            xAxis: {
                type: 'datetime',
                dateTimeLabelFormats: {
                    second: '%H:%M:%S'
                }
            },
            yAxis: {
                title: {
                    text: 'Pressure (hPa)'
                }
            },
            credits: {
                enabled: false
            }
        });
        setInterval(function() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    var x = (new Date()).getTime(),
                        y = parseFloat(this.responseText);
                    //console.log(this.responseText);
                    if (chartP.series[0].data.length > 40) {
                        chartP.series[0].addPoint([x, y], true, true, true);
                    } else {
                        chartP.series[0].addPoint([x, y], true, false, true);
                    }
                }
            };
            xhttp.open("GET", "/pressure", true);
            xhttp.send();
        }, 10000);
        var chartR = new Highcharts.Chart({
            chart: {
                renderTo: 'chart-rain',
                backgroundColor: "rgba(255, 255, 255, 0.3)",
                height: 'inherit',
            },
            title: {
                text: ' RAIN'
            },
            series: [{
                name: 'mm',
                showInLegend: false,
                data: []
            }],
            plotOptions: {
                line: {
                    animation: false,
                    dataLabels: {
                        enabled: true
                    }
                },
                series: {
                    color: '#059e8a'
                }
            },

            xAxis: {
                type: 'datetime',
                dateTimeLabelFormats: {
                    second: '%H:%M:%S'
                }
            },

            yAxis: {
                title: {
                    text: 'RAIN '
                }

            },
            credits: {
                enabled: false
            }
        });
        setInterval(function() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    var x = (new Date()).getTime(),
                        y = parseFloat(this.responseText);
                    //console.log(this.responseText);
                    if (chartR.series[0].data.length > 40) {
                        chartR.series[0].addPoint([x, y], true, true, true);
                    } else {
                        chartR.series[0].addPoint([x, y], true, false, true);
                    }
                }
            };
            xhttp.open("GET", "/water_level", true);
            xhttp.send();
        }, 10000);
        var chartW = new Highcharts.Chart({
            chart: {
                renderTo: 'chart-wind',
                backgroundColor: "rgba(255, 255, 255, 0.3)",
                height: 'inherit',
            },
            title: {
                text: ' WIND'
            },
            series: [{
                name: 'WIND',
                showInLegend: false,
                data: []
            }],
            plotOptions: {
                line: {
                    animation: false,
                    dataLabels: {
                        enabled: true
                    }
                },
                series: {
                    color: '#059e8a'
                }
            },

            xAxis: {
                type: 'datetime',
                dateTimeLabelFormats: {
                    second: '%H:%M:%S'
                }
            },

            yAxis: {
                title: {
                    text: 'Km/h '
                }

            },
            credits: {
                enabled: false
            }
        });
        setInterval(function() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    var x = (new Date()).getTime(),
                        y = parseFloat(this.responseText);
                    //console.log(this.responseText);
                    if (chartW.series[0].data.length > 40) {
                        chartW.series[0].addPoint([x, y], true, true, true);
                    } else {
                        chartW.series[0].addPoint([x, y], true, false, true);
                    }
                }
            };
            xhttp.open("GET", "/wind", true);
            xhttp.send();
        }, 10000);
        /* - and +  */
        $(".next").on("click", function() {
            var $button = $(this);
            var oldValue = $button.parent().find("input").val();
            if (oldValue >= 60) {
                var newVal = 0;

            } else {
                var newVal = parseFloat(oldValue) + 1
            }

            $button.parent().find("input").val(newVal);

        });
        $(".prev").on("click", function() {
            var $button = $(this);
            var oldValue = $button.parent().find("input").val();
            if (oldValue <= 0) {
                var newVal = 60;

            } else {
                var newVal = parseFloat(oldValue) - 1
            }

            $button.parent().find("input").val(newVal);

        })
    </script>
    <script type="text/javascript">
        function toggle() {
            var blur = document.getElementById('blur');
            blur.classList.toggle('active');

        }
    </script>

    <script>
        /*notifs inside page*/
        var ct, cp, ch;
        setInterval(function() {
            realt = 30;
            /*temperature notifs*/
            if (checkt == "1") {
                if (realtemp < mintemp) {
                    document.querySelector('.alert1').style.display = "block";
                    document.querySelector('.alert2').style.display = "none";
                    ct = 1;
                } else if (realtemp > maxtemp) {
                    document.querySelector('.alert2').style.display = "block";
                    document.querySelector('.alert1').style.display = "none";
                    ct = 1;

                } else {
                    ct = 0
                    document.querySelector('.alert1').style.display = "none";
                    document.querySelector('.alert2').style.display = "none";
                }
            } else {
                document.querySelector('.alert1').style.display = "none";
                document.querySelector('.alert2').style.display = "none";
                ct = 0;
            }


            /* humidity notifs*/
            if (checkh == "1") {
                if (realhumi < minhumi) {
                    ch = 1;
                    document.querySelector('.alert5').style.display = "block";
                    document.querySelector('.alert6').style.display = "none";
                } else if (realhumi > maxhumi) {
                    ch = 1;
                    document.querySelector('.alert6').style.display = "block";
                    document.querySelector('.alert5').style.display = "none";

                } else {
                    document.querySelector('.alert5').style.display = "none";
                    document.querySelector('.alert6').style.display = "none";
                    ch = 0;
                }
            } else {
                document.querySelector('.alert5').style.display = "none";
                document.querySelector('.alert6').style.display = "none";
                ch = 0;
            }

            /* pressure notifs*/
            if (checkp == "1") {
                if (realpress < minpress) {
                    cp = 1;
                    document.querySelector('.alert3').style.display = "block";
                    document.querySelector('.alert4').style.display = "none";
                } else if (realpress > maxpress) {
                    cp = 1;
                    document.querySelector('.alert4').style.display = "block";
                    document.querySelector('.alert3').style.display = "none";

                } else {
                    cp = 0;
                    document.querySelector('.alert3').style.display = "none";
                    document.querySelector('.alert4').style.display = "none";
                }
            } else {
                cp = 0;
                document.querySelector('.alert3').style.display = "none";
                document.querySelector('.alert4').style.display = "none";
            }
            total = ct + ch + cp;
            var tot = total;
            $(".closebtn2").click(function() {

                tot = tot - 1;
                if (tot == 0) {
                    $(".allnum").hide();
                } else {
                    $(".allnum").html(tot);
                    $(".allnum").show();
                }


            });
            $("#clearall").click(function() {
                $(".allnum").hide();
            });
            if (total == 0) {

                $(".allnum").hide(200);
            } else {
                $(".allnum").html(total);
                $(".allnum").show();

            }

        }, 8000);
        /*notif  showing on desktop*/
        // function showNotification1() {

        //     const notification = new Notification("new alert from ESI WEATHER !", {
        //         body: "The temperature is out of range , check your station",
        //         icon: "https://i.ibb.co/Yfxw86F/logo1.png"
        //     });
        //     notification.onclick = (e) => {
        //         window.location.href = "http://esisbameteo.ddns.net"
        //     }
        // }

        // function showNotification2() {

        //     const notification = new Notification("new alert from ESI WEATHER !", {
        //         body: "The HUMIDITY is out of range , check your station",
        //         icon: "https://i.ibb.co/Yfxw86F/logo1.png"
        //     });
        //     notification.onclick = (e) => {
        //         window.location.href = "http://esisbameteo.ddns.net"
        //     }
        // }

        // function showNotification3() {

        //     const notification = new Notification("new alert from ESI WEATHER !", {
        //         body: "The PRESSURE is Out of range , check your station",
        //         icon: "https://i.ibb.co/Yfxw86F/logo1.png"
        //     });
        //     notification.onclick = (e) => {
        //         window.location.href = "http://esisbameteo.ddns.net"
        //     }
        // }

        // /*desktop notifs*/

        // setInterval(function() {
        //     if (Notification.permission === "granted") {
        //         if (ct == 1) {
        //             showNotification1();

        //         };
        //         if (ch == 1) {
        //             showNotification2();

        //         };
        //         if (cp == 1) {
        //             showNotification3();

        //         };


        //     } else if (Notification.permission !== "denied") {
        //         Notification.requestPermission().then(permission => {
        //             if (permission === "granted") {
        //                 if (ct == 1) {
        //                     showNotification1();

        //                 };
        //                 if (ch == 1) {
        //                     showNotification2();

        //                 };
        //                 if (cp == 1) {
        //                     showNotification3();

        //                 };
        //             }
        //         })
        //     }

        // }, 15000);
        //ADDED
    </script>

</body>

</html>)=====";
