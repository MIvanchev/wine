#ifndef __WINE_MESA_LOADER_H
#define __WINE_MESA_LOADER_H

#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <alloca.h>
#include <wine/debug.h>

/* OpenGL, OSMesa, EGL, Vulkan etc. are statically linked in
 * winex11.so so to avoid linking them a second time we load
 * winex11.so through a dirty hack and import the symbols from
 * there.
 */

static void* get_handle_to_mesa(void)
{
    Dl_info info;
    const char *last_path_sep;
    size_t path_len;
    char *winex11_so_path;
    void *handle;

    if (!dladdr(get_handle_to_mesa, &info)
            || !(last_path_sep = strrchr(info.dli_fname, '/')))
    {
        ERR( "Failed to determine absoltue path to Wine's SO files.\n" );
        return NULL;
    }

    path_len = last_path_sep - info.dli_fname + 1;
    winex11_so_path = alloca(path_len + strlen("winex11.so") + 1);
    memcpy(winex11_so_path, info.dli_fname, path_len);
    strcpy(winex11_so_path + path_len, "winex11.so");

    if (!(handle = dlopen(winex11_so_path, RTLD_LAZY | RTLD_LOCAL)))
    {
        ERR( "Failed to load %s containing statically linked Mesa: %s\n", winex11_so_path, dlerror() );
        return NULL;
    }

    return handle;
}

#endif /* __WINE_MESA_LOADER_H */
