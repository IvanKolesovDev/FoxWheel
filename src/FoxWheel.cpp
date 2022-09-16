#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{

    HWND hwnd;               /* This is the handle for our window */
    MSG msg;            /* Here messages to the application are saved */
    WNDCLASSEX fwWindowClass;        /* Data structure for the windowclass */

    /* The Window structure */
    fwWindowClass.hInstance = hThisInstance;
    fwWindowClass.lpszClassName = szClassName;
    fwWindowClass.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    fwWindowClass.style = CS_DBLCLKS;                 /* Catch double-clicks */
    fwWindowClass.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    fwWindowClass.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    fwWindowClass.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    fwWindowClass.hCursor = LoadCursor (NULL, IDC_ARROW);
    fwWindowClass.lpszMenuName = NULL;                 /* No menu */
    fwWindowClass.cbClsExtra = 0;                      /* No extra bytes after the window class */
    fwWindowClass.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    fwWindowClass.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&fwWindowClass))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Fox Wheel engine"),
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1024,                 /* The programs width */
           768,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    while(TRUE)
    {
        // Check to see if any messages are waiting in the queue
        while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            // Translate the message and dispatch it to WindowProc()
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // If the message is WM_QUIT, exit the while loop
        if(msg.message == WM_QUIT)
            break;

        // Run game code here
        // ...
        // ...
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return msg.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
