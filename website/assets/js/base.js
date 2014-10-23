$(document).ready(function()
{
	$("#arrow_left").addClass("hidden");
	function startTime() 
	{
		var today=new Date();
		var h=today.getHours();
		var m=today.getMinutes();
		var s=today.getSeconds();
		var TOD = "am";
		if(h > 12)
		{
			TOD = "pm";
			h = h-12;
		}
		m = checkTime(m);
		s = checkTime(s);
		var colon = ":";
		var time = h + colon + m + colon + s + " " +TOD;
		$($(".currentTime")[0]).html(time);
		var t = setTimeout(function(){startTime();},500);
		function checkTime(i) 
		{
			if (i<10)
				i = "0"+i;
			return i;
		}
	}
	startTime();
	var windowWidth, windowHeight;
	function getWindowDimensions()
	{
		if(typeof(window.innerWidth)=='number')
		{
			windowWidth=window.innerWidth;
			windowHeight=window.innerHeight;
		}
		else if(document.documentElement&&(document.documentElement.clientWidth||document.documentElement.clientHeight))
		{
			windowWidth=document.documentElement.clientWidth;
			windowHeight=document.documentElement.clientHeight;
		}
		else if(document.body&&(document.body.clientWidth||document.body.clientHeight))
		{
			windowWidth=document.body.clientWidth;
			windowHeight=document.body.clientHeight;
		}
	}
	getWindowDimensions();
	$("#arrow_left").click(function(){Reveal.prev();});
	$("#arrow_right").click(function(){Reveal.next();});
	Reveal.addEventListener('slidechanged',function(event)
	{
		window.temp = event;
		if(Reveal.isFirstSlide())
		{
			$("#arrow_left").fadeOut();
			$("#arrow_right").fadeIn();
		}
		else if(Reveal.isLastSlide())
		{
			$("#arrow_left").fadeIn();
			$("#arrow_right").fadeOut();
		}
		else
		{
			$("#arrow_left").fadeIn();
			$("#arrow_right").fadeIn();
		}
	});
	function wwr_lastSlide(){Reveal.navigateTo(7);}
	$(".map").click(function(){wwr_lastSlide();});
	$(".credits").click(function(){wwr_lastSlide();});
	$(".gallery").click(function(){wwr_lastSlide();});
});