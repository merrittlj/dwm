/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "AnonymousPro:size=12" };
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_second[]      = "#602c94";

static const char fg[]          = "#dcd8c0";
static const char bg[]          = "#bab5a1";
static const char acc[]         = "#454138";
static const char fg1[]         = "#282828";
static const char bg1[]         = "#f2e5bc";
static const char acc1[]        = "#d79921";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = {acc,bg,fg},
	[SchemeSel]  = {fg,acc,acc},
};

/* tagging */
static const char *tags[] = { "nil", "edit", "www", "com", "misc" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title                      tags mask     isfloating   monitor */
	{ NULL,       NULL,       "GNU Image",               1 << 1,            0,           -1 },
	{ NULL,       NULL,       "Mozilla Firefox",         1 << 2,            0,           -1 },
    { NULL,       NULL,       "GNU Emacs",               1 << 1,            0,           -1 },
    { NULL,       NULL,       "LibreOffice",             1 << 1,            0,           -1 },
    { NULL,       NULL,       "NVIDIA Settings",         1 << 1,            0,           -1 },
    { NULL,       NULL,       "Audacity",                1 << 1,            0,           -1 },
    { NULL,       NULL,       "st",                      0,                 0,           -1 },
    { NULL,       NULL,       "Volume Control",          0,                 0,           -1 },
    { NULL,       NULL,       "Steam",                   1 << 4,            0,           -1 },
    { NULL,       NULL,       "Minecraft Launcher",      1 << 4,            0,           -1 },
    { NULL,       NULL,       "Lutris",                  1 << 4,            0,           -1 }
    // email/chat/irc client on tag #4(1 << 3)
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "&",      dwindle},
	{ "-",      tile },    /* first entry is default */
	{ "*",      NULL },    /* no layout function means floating behavior */
	{ ".",      monocle },
	{ "@",      spiral },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { "st", NULL };

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          SHCMD("LD_LIBRARY_PATH=/home/lucas/builds/bemenu BEMENU_RENDERERS=/home/lucas/builds/bemenu bemenu-run -p bemenu -B 1 -P -- -M 100 -c --fn \"Anonymous Pro 12\" --fixed-height --counter always --tb \"#454138\" --tf \"#dcd8c0\" --fb \"#bab5a1\" --ff \"#454138\" --nb \"#bab5a1\" --nf \"#454138\" --hb \"#bab5a1\" --hf \"#ce664d\" -fbb \"#bab5a1\"--fbf \"#4541348\" --sb \"#bab5a1\" --sf \"#454138\" --ab \"#bab5a1\" --af \"#454138\" --scb \"#bab5a1\" --scf \"#454138\" --bdr \"#454138\" -l 10") },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_y,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_r,      reorganizetags, {0} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_x,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_ampersand,              0)
	TAGKEYS(                        XK_bracketleft,            1)
	TAGKEYS(                        XK_braceleft,              2)
	TAGKEYS(                        XK_braceright,             3)
	TAGKEYS(                        XK_parenleft,              4)
	TAGKEYS(                        XK_equal,                  5)
	TAGKEYS(                        XK_asterisk,               6)
	TAGKEYS(                        XK_parenright,             7)
	TAGKEYS(                        XK_plus,                   8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

