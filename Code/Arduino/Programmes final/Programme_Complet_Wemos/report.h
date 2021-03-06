const char index_html_report[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">

<head>

    <title>Report</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
    <link rel="shortcut icon" href="https://i.ibb.co/PC8DYtT/clouds.png">
    <link href="https://cdn.datatables.net/1.10.21/css/jquery.dataTables.min.css" rel="stylesheet" type="text/css">
    <script src="https://kit.fontawesome.com/d7c9c3d618.js"></script>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@200&display=swap" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css2?family=Pacifico&family=Piedra&family=Raleway:wght@600&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.4.1/css/all.css">
    <script src="https://www.gstatic.com/firebasejs/3.1.0/firebase.js"></script>
    <script src="https://code.jquery.com/jquery-3.5.1.js"></script>
    <script src="https://cdn.datatables.net/1.10.21/js/jquery.dataTables.min.js"></script>
    <script src="https://code.highcharts.com/highcharts.js"></script>
    <script src="https://code.highcharts.com/modules/series-label.js"></script>
    <script src="https://code.highcharts.com/modules/exporting.js"></script>
    <script src="https://code.highcharts.com/modules/export-data.js"></script>
    <script src="https://code.highcharts.com/modules/accessibility.js"></script>


    <style>
        .highcharts-data-table table {
            min-width: 360px;
            max-width: 100%;
            margin: 1em auto;
        }
        
        .highcharts-data-table table {
            font-family: Verdana, sans-serif;
            border-collapse: collapse;
            border: 1px solid #EBEBEB;
            margin: 10px auto;
            text-align: center;
            width: 90%;
            max-width: 500px;
        }
        
        .highcharts-data-table caption {
            padding: 1em 0;
            font-size: 1.2em;
            color: #555;
        }
        
        .highcharts-data-table th {
            font-weight: 600;
            padding: 0.5em;
        }
        
        .highcharts-data-table td,
        .highcharts-data-table th,
        .highcharts-data-table caption {
            padding: 0.5em;
        }
        
        .highcharts-data-table thead tr,
        .highcharts-data-table tr:nth-child(even) {
            background: #f8f8f88f;
        }
        
        .highcharts-data-table tr:hover {
            background: #f1f7ff;
        }
        /*background*/
        
        html,
        body {
            margin: 0;
            padding: 0;
            width: 100%;
            scroll-behavior: smooth;
        }
        
        body {
            font-family: poppins;
            background-image: url(https://i.ibb.co/QMtQfzq/sky3.jpg);
            background-size: cover;
            background-attachment: fixed;
            box-sizing: border-box;
        }
        
        #body {
            padding: 20px;
            box-sizing: border-box;
        }
        
        header {
            width: 100%;
            height: 9vh;
        }
        
        h2 {
            color: #fff;
            text-shadow: 2px 2px 1px rgba(252, 169, 15, 0.945);
            font-size: 44px;
            font-family: 'poppins';
            font-weight: bolder;
            justify-content: center;
            text-align: center;
        }
        
        @media (max-width: 365px) {
            h2 {
                font-size: 38px;
            }
        }
        
        .logo {
            position: fixed;
            float: left;
        }
        
        #logoimg {
            width: 140px;
            height: 65px;
            margin-left: 20px;
            margin-top: 7px;
            opacity: 0.95;
        }
        
        nav {
            z-index: 1000;
            position: fixed;
            width: 100%;
        }
        
        nav ul {
            list-style: none;
            background: rgba(0, 0, 0, 0);
            overflow: hidden;
            text-shadow: 1px 1px 2px rgba(194, 192, 192, 0.877);
            color: #fff;
            padding: 0;
            text-align: center;
            margin: 0;
            margin-right: 50px;
            transition: .8s;
        }
        
        nav.black {
            background: #fccb43fa;
        }
        
        nav ul li {
            padding: 20px;
            text-align: center;
            float: right;
        }
        
        nav ul li a {
            text-decoration: none;
            color: #fff;
            font-size: 25px;
        }
        /*responsive nav*/
        
        @media(max-width: 780px) {
            #logoimg {
                height: 50px;
                width: 100px;
                margin-right: 10px;
                opacity: 1;
                margin-top: 10px;
                margin-left: 0px;
            }
            .logo {
                position: fixed;
                top: 0;
                margin-top: 0px;
            }
            nav {
                background-color: rgba(0, 0, 0, 0);
            }
            .menu {
                padding-right: 20px;
            }
            nav ul {
                margin-right: 1%;
            }
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
        /*spn*/
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

        /* footer section */
        
        #example {
            background-color: rgba(255, 255, 255, 0.3);
            text-transform: capitalize;
            color: rgb(0, 0, 0);
            font-size: 95%;
            font-family: Arial, Helvetica, sans-serif;
            max-width: 95%;
        }
        
        #example_wrapper {
            width: 100%;
            background-color: #b5cee734;
        }
        
        #example_length,
        #example_filter,
        #example_paginate,
        #example_info {
            font-family: Arial, Helvetica, sans-serif;
            padding: 10px;
            color: #ffffff;
            font-weight: bolder;
        }
        
        #example_paginate {
            border-radius: 10%;
        }
        
        td {
            font-family: Arial, Helvetica, sans-serif;
            color: black;
        }
        
        .sec#blur.active {
            filter: blur(5px)
        }
        
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
        /*account section css*/
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
            width: 80%;
        }
        
        .rightbox h2 {
            color: #777;
            font-family: "Roboto", sans-serif;
            text-transform: uppercase;
            font-size: 8px;
            letter-spacing: 1px;
            margin-left: 2px;
            margin-top: 10px;
            text-shadow: none;
            text-align: left;
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
            left: 30%;
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
                left: 30%;
                margin-top: 23px
            }
            .profile {
                margin-left: 13px;
            }
            .action p {
                text-align: left;
                padding-left: 20px;
            }
            .menu li {
                padding-right: 5px;
                padding-left: 6px;
            }
            .menu li a {
                font-size: 22px;
            }
        }
        /* checkbox ACTIONS */
        
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
        }
    </style>

</head>


<body>

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
    <script type="text/javascript">
        // code of scroll animation
        $(window).on("scroll", function() {
            if ($(window).scrollTop()) {
                $('nav').addClass('black');
            } else {
                $('nav').removeClass('black');
            }
        });
    </script>


    <header>
        <nav>
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

            <script type="text/javascript">
                function toggle() {
                    var blur = document.getElementById('blur');
                    blur.classList.toggle('active')
                }
            </script>
            <script>
                const tabBtn = document.querySelectorAll(".tab");
                const tabl = document.querySelectorAll(".tabShow");

                function tabs(panelIndex) {
                    tabl.forEach(function(node) {
                        node.style.display = "none";
                    });
                    tabl[panelIndex].style.display = "block";
                }

                tabs(0);

                $(".tab").click(function() {
                    $(this).addClass("active").siblings().removeClass("active");
                });
            </script>
            <div class="logo">
                <img alt="logo" src="https://i.ibb.co/Yfxw86F/logo1.png" id="logoimg">
            </div>
            <label for="check">
            <i class="fas fa-user-circle" id="sidebar_btn" onclick="toggle()"></i>
           </label>
            <div class="menu">
                <ul>

                    <li><a href="http://esisbameteo.ddns.net" onclick="logout()" id="logout_butt">Logout</a></li>

                    <li><a href="http://esisbameteo.ddns.net">Home</a></li>


                </ul>
            </div>
        </nav>
    </header>
    <div class="sec" id="blur">
        <div id="body">
            <br/> <br/>
            <figure class="highcharts-figure">
                <div id="container"></div>

            </figure><br/><br/> <br/>
            <h2>
                <&nbsp; DATA TABLE &nbsp;>
            </h2>


            <table id="example" class="display" width="100%"></table>
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

            /*infos*/
         /*   firebase.auth().onAuthStateChanged(function(user) {
                        if (user) {
                            var user = firebase.auth().currentUser;
                            if (user.emailVerified) {
                                function gotData(data) {
                                    let x = data.val();

                                    document.getElementById("userNameInputField").value = x[userId].username || 'Anonymous';
                                    document.getElementById("emailInputField").value = user.email;
                                    document.getElementById("phoneNumberInputField").value = x[userId].phone_number || 'No phone number';
                                }
                            }
                        }
                    }*/
        </script>


</body>
<script>
    var database = firebase.database().ref("/DATA/").on('value', gotData, errData);


    function gotData(data) {

        let tabtimes = [];
        let tabtempc = [];
        let tabtempf = [];
        let tabhum = [];
        let tabpress = [];
        let tabpdr = [];
        let tabpluie = [];
        let dataa
        let times;
        let dataSet = [];

        var daysObject = data.val();
        // alert("daysObject : "+daysObject);
        var days = Object.keys(daysObject);
        //alert("days : "+days);
        //alert("day.length : "+days.length());
        for (let dayindex = 0; dayindex < days.length; dayindex++) {
            var day = days[dayindex];
            //alert("day : "+day);

            //tab.push(day);
            var timesObject = daysObject[day];
            //alert("timesObject : "+timesObject);
            times = Object.keys(timesObject);
            if (tabtimes == []) {
                /*for (let index = 0; index < times.length; index++) {
                     tabtimes.push (day+"/"+times[index]);
                     alert("tabtimes : "+tabtimes);

                }*/
                tabtimes = times;
            } else {
                tabtimes.push.apply(tabtimes, times);
                //alert("tabtimes : "+tabtimes);
                //alert("test ");
            }
            // alert("times : "+times);




            for (let index = 0; index < times.length; index++) {
                tab = [day];
                var time = times[index];
                //alert("time : "+time);
                tab.push.apply(tab, [time]);

                var keys = Object.keys(timesObject[time]);
                //alert ("keys : "+keys);
                for (let j = 0; j < keys.length; j++) {
                    let k = keys[j];
                    //alert ("k : " + k);
                    dataa = timesObject[time];
                    //alert ("dataa : "+dataa);
                    //alert(Object.keys(dataa));
                    //console.log(dataa);
                    tab.push(dataa[k]);

                }
                tabtempc.push(parseFloat(dataa[keys[0]]));
                tabtempf.push(parseFloat(dataa[keys[1]]));
                tabhum.push(parseFloat(dataa[keys[2]]));
                tabpress.push(parseFloat(dataa[keys[4]]));
                tabpdr.push(parseFloat(dataa[keys[5]]));
                tabpluie.push(parseFloat(dataa[keys[6]]));
                //
                dataSet.push.apply(dataSet, [tab]);
            }






            $(document).ready(function() {
                $.fn.dataTable.ext.errMode = 'none';
                $('#example').DataTable({

                    data: dataSet,
                    columns: [{
                            title: "Date"
                        }, {
                            title: "Time"
                        }, {
                            title: "Temperature in celsius"
                        }, {
                            title: "Temperature in fahrenheit"
                        }, {
                            title: "Humidity"
                        }, {
                            title: "Water Level"
                        }, {
                            title: "Pressure"
                        }, {
                            title: "Dew Point"
                        }, {
                            title: "Rain"
                        }


                    ]
                });

            });
        }
        Highcharts.chart('container', {
            chart: {
                type: 'line',
                zoomType: 'x',
                backgroundColor: 'rgba(255, 255, 255, 0.3)',

            },
            credits: {
                enabled: false
            },
            title: {
                text: 'Graphs of data from firebase'
            },

            subtitle: null,

            yAxis: {
                title: {
                    text: 'value'
                }
            },

            xAxis: {
                title: {
                    text: 'Time'
                },
                /*minorTickInterval: 3,
                    accessibility: {
                        rangeDescription: 'Range: 0 to 20'
                    }*/
            },

            legend: {
                layout: 'vertical',
                align: 'right',
                verticalAlign: 'middle'
            },

            plotOptions: {
                series: {
                    label: {
                        connectorAllowed: false
                    },
                    pointStart: 0
                }
            },

            series: [{

                name: 'Temperature in celsius',
                data: tabtempc


            }, {
                name: 'Temperature in fahrenheit',
                data: tabtempf
            }, {
                name: 'Humidity',
                data: tabhum
            }, {
                name: 'Pressure',
                data: tabpress
            }, {
                name: 'Dew Point',
                data: tabpdr
            }, {
                name: 'Rain',
                data: tabpluie
            }],


            xAxis: {
                categories: tabtimes
            },

            responsive: {
                rules: [{
                    condition: {
                        maxWidth: 2000
                    },
                    chartOptions: {
                        legend: {
                            layout: 'horizontal',
                            align: 'center',
                            verticalAlign: 'bottom'
                        }
                    }
                }]
            }

        });
        tabtimes = [];
        //alert(" tabtimes : "+ tabtimes)
    }


    function errData(err) {
        console.log(err);
        alert('error!!');
    }

    function logout() {


        var user = firebase.auth().currentUser;
        if (user != null) {

            let email_id = user.email;
            alert("goodbye User : " + email_id);
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





        firebase.auth().signOut();

    }
    /**/
    var ct, cp, ch;
    setInterval(function() {
        realt = 30;
        /*temperature notifs*/
        if (checkt == "1") {
            if (realt < mintemp) {
                document.querySelector('.alert1').style.display = "block";
                document.querySelector('.alert2').style.display = "none";
                ct = 1;
            } else if (realt > maxtemp) {
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

</script>

</html>)=====";
