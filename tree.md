
```
344E-VEXCODE-2526
├─ include
│  ├─ autons.h
│  ├─ JAR-Template
│  │  ├─ drive.h
│  │  ├─ odom.h
│  │  ├─ PID.h
│  │  └─ util.h
│  ├─ robot-config.h
│  ├─ sylib
│  │  ├─ addrled.hpp
│  │  ├─ env.hpp
│  │  ├─ math.hpp
│  │  ├─ motor.hpp
│  │  ├─ sylib.hpp
│  │  ├─ sylib_apitypes.hpp
│  │  └─ system.hpp
│  ├─ v5lvgl.h
│  └─ vex.h
├─ lvgl
│  ├─ lvgl.h
│  ├─ lv_conf.h
│  └─ src
│     ├─ core
│     │  ├─ lv_core.mk
│     │  ├─ lv_disp.c
│     │  ├─ lv_disp.h
│     │  ├─ lv_event.c
│     │  ├─ lv_event.h
│     │  ├─ lv_group.c
│     │  ├─ lv_group.h
│     │  ├─ lv_indev.c
│     │  ├─ lv_indev.h
│     │  ├─ lv_indev_scroll.c
│     │  ├─ lv_indev_scroll.h
│     │  ├─ lv_obj.c
│     │  ├─ lv_obj.h
│     │  ├─ lv_obj_class.c
│     │  ├─ lv_obj_class.h
│     │  ├─ lv_obj_draw.c
│     │  ├─ lv_obj_draw.h
│     │  ├─ lv_obj_pos.c
│     │  ├─ lv_obj_pos.h
│     │  ├─ lv_obj_scroll.c
│     │  ├─ lv_obj_scroll.h
│     │  ├─ lv_obj_style.c
│     │  ├─ lv_obj_style.h
│     │  ├─ lv_obj_style_gen.c
│     │  ├─ lv_obj_style_gen.h
│     │  ├─ lv_obj_tree.c
│     │  ├─ lv_obj_tree.h
│     │  ├─ lv_refr.c
│     │  ├─ lv_refr.h
│     │  ├─ lv_theme.c
│     │  └─ lv_theme.h
│     ├─ draw
│     │  ├─ arm2d
│     │  │  ├─ lv_draw_arm2d.mk
│     │  │  ├─ lv_gpu_arm2d.c
│     │  │  └─ lv_gpu_arm2d.h
│     │  ├─ lv_draw.c
│     │  ├─ lv_draw.h
│     │  ├─ lv_draw.mk
│     │  ├─ lv_draw_arc.c
│     │  ├─ lv_draw_arc.h
│     │  ├─ lv_draw_img.c
│     │  ├─ lv_draw_img.h
│     │  ├─ lv_draw_label.c
│     │  ├─ lv_draw_label.h
│     │  ├─ lv_draw_layer.c
│     │  ├─ lv_draw_layer.h
│     │  ├─ lv_draw_line.c
│     │  ├─ lv_draw_line.h
│     │  ├─ lv_draw_mask.c
│     │  ├─ lv_draw_mask.h
│     │  ├─ lv_draw_rect.c
│     │  ├─ lv_draw_rect.h
│     │  ├─ lv_draw_transform.c
│     │  ├─ lv_draw_transform.h
│     │  ├─ lv_draw_triangle.c
│     │  ├─ lv_draw_triangle.h
│     │  ├─ lv_img_buf.c
│     │  ├─ lv_img_buf.h
│     │  ├─ lv_img_cache.c
│     │  ├─ lv_img_cache.h
│     │  ├─ lv_img_decoder.c
│     │  ├─ lv_img_decoder.h
│     │  ├─ nxp
│     │  │  ├─ lv_draw_nxp.mk
│     │  │  ├─ pxp
│     │  │  │  ├─ lv_draw_nxp_pxp.mk
│     │  │  │  ├─ lv_draw_pxp.c
│     │  │  │  ├─ lv_draw_pxp.h
│     │  │  │  ├─ lv_draw_pxp_blend.c
│     │  │  │  ├─ lv_draw_pxp_blend.h
│     │  │  │  ├─ lv_gpu_nxp_pxp.c
│     │  │  │  ├─ lv_gpu_nxp_pxp.h
│     │  │  │  ├─ lv_gpu_nxp_pxp_osa.c
│     │  │  │  └─ lv_gpu_nxp_pxp_osa.h
│     │  │  └─ vglite
│     │  │     ├─ lv_draw_nxp_vglite.mk
│     │  │     ├─ lv_draw_vglite.c
│     │  │     ├─ lv_draw_vglite.h
│     │  │     ├─ lv_draw_vglite_arc.c
│     │  │     ├─ lv_draw_vglite_arc.h
│     │  │     ├─ lv_draw_vglite_blend.c
│     │  │     ├─ lv_draw_vglite_blend.h
│     │  │     ├─ lv_draw_vglite_line.c
│     │  │     ├─ lv_draw_vglite_line.h
│     │  │     ├─ lv_draw_vglite_rect.c
│     │  │     ├─ lv_draw_vglite_rect.h
│     │  │     ├─ lv_vglite_buf.c
│     │  │     ├─ lv_vglite_buf.h
│     │  │     ├─ lv_vglite_utils.c
│     │  │     └─ lv_vglite_utils.h
│     │  ├─ sdl
│     │  │  ├─ lv_draw_sdl.c
│     │  │  ├─ lv_draw_sdl.h
│     │  │  ├─ lv_draw_sdl.mk
│     │  │  ├─ lv_draw_sdl_arc.c
│     │  │  ├─ lv_draw_sdl_bg.c
│     │  │  ├─ lv_draw_sdl_composite.c
│     │  │  ├─ lv_draw_sdl_composite.h
│     │  │  ├─ lv_draw_sdl_img.c
│     │  │  ├─ lv_draw_sdl_img.h
│     │  │  ├─ lv_draw_sdl_label.c
│     │  │  ├─ lv_draw_sdl_layer.c
│     │  │  ├─ lv_draw_sdl_layer.h
│     │  │  ├─ lv_draw_sdl_line.c
│     │  │  ├─ lv_draw_sdl_mask.c
│     │  │  ├─ lv_draw_sdl_mask.h
│     │  │  ├─ lv_draw_sdl_polygon.c
│     │  │  ├─ lv_draw_sdl_priv.h
│     │  │  ├─ lv_draw_sdl_rect.c
│     │  │  ├─ lv_draw_sdl_rect.h
│     │  │  ├─ lv_draw_sdl_stack_blur.c
│     │  │  ├─ lv_draw_sdl_stack_blur.h
│     │  │  ├─ lv_draw_sdl_texture_cache.c
│     │  │  ├─ lv_draw_sdl_texture_cache.h
│     │  │  ├─ lv_draw_sdl_utils.c
│     │  │  ├─ lv_draw_sdl_utils.h
│     │  │  └─ README.md
│     │  ├─ stm32_dma2d
│     │  │  ├─ lv_draw_stm32_dma2d.mk
│     │  │  ├─ lv_gpu_stm32_dma2d.c
│     │  │  └─ lv_gpu_stm32_dma2d.h
│     │  ├─ sw
│     │  │  ├─ lv_draw_sw.c
│     │  │  ├─ lv_draw_sw.h
│     │  │  ├─ lv_draw_sw.mk
│     │  │  ├─ lv_draw_sw_arc.c
│     │  │  ├─ lv_draw_sw_blend.c
│     │  │  ├─ lv_draw_sw_blend.h
│     │  │  ├─ lv_draw_sw_dither.c
│     │  │  ├─ lv_draw_sw_dither.h
│     │  │  ├─ lv_draw_sw_gradient.c
│     │  │  ├─ lv_draw_sw_gradient.h
│     │  │  ├─ lv_draw_sw_img.c
│     │  │  ├─ lv_draw_sw_layer.c
│     │  │  ├─ lv_draw_sw_letter.c
│     │  │  ├─ lv_draw_sw_line.c
│     │  │  ├─ lv_draw_sw_polygon.c
│     │  │  ├─ lv_draw_sw_rect.c
│     │  │  └─ lv_draw_sw_transform.c
│     │  └─ swm341_dma2d
│     │     ├─ lv_draw_swm341_dma2d.mk
│     │     ├─ lv_gpu_swm341_dma2d.c
│     │     └─ lv_gpu_swm341_dma2d.h
│     ├─ extra
│     │  ├─ layouts
│     │  │  ├─ flex
│     │  │  │  ├─ lv_flex.c
│     │  │  │  └─ lv_flex.h
│     │  │  ├─ grid
│     │  │  │  ├─ lv_grid.c
│     │  │  │  └─ lv_grid.h
│     │  │  └─ lv_layouts.h
│     │  ├─ libs
│     │  │  ├─ bmp
│     │  │  │  ├─ lv_bmp.c
│     │  │  │  └─ lv_bmp.h
│     │  │  ├─ ffmpeg
│     │  │  │  ├─ lv_ffmpeg.c
│     │  │  │  └─ lv_ffmpeg.h
│     │  │  ├─ freetype
│     │  │  │  ├─ arial.ttf
│     │  │  │  ├─ lv_freetype.c
│     │  │  │  └─ lv_freetype.h
│     │  │  ├─ fsdrv
│     │  │  │  ├─ lv_fsdrv.h
│     │  │  │  ├─ lv_fs_fatfs.c
│     │  │  │  ├─ lv_fs_posix.c
│     │  │  │  ├─ lv_fs_stdio.c
│     │  │  │  └─ lv_fs_win32.c
│     │  │  ├─ gif
│     │  │  │  ├─ gifdec.c
│     │  │  │  ├─ gifdec.h
│     │  │  │  ├─ lv_gif.c
│     │  │  │  └─ lv_gif.h
│     │  │  ├─ lv_libs.h
│     │  │  ├─ png
│     │  │  │  ├─ lodepng.c
│     │  │  │  ├─ lodepng.h
│     │  │  │  ├─ lv_png.c
│     │  │  │  └─ lv_png.h
│     │  │  ├─ qrcode
│     │  │  │  ├─ lv_qrcode.c
│     │  │  │  ├─ lv_qrcode.h
│     │  │  │  ├─ qrcodegen.c
│     │  │  │  └─ qrcodegen.h
│     │  │  ├─ rlottie
│     │  │  │  ├─ lv_rlottie.c
│     │  │  │  └─ lv_rlottie.h
│     │  │  └─ sjpg
│     │  │     ├─ lv_sjpg.c
│     │  │     ├─ lv_sjpg.h
│     │  │     ├─ tjpgd.c
│     │  │     ├─ tjpgd.h
│     │  │     └─ tjpgdcnf.h
│     │  ├─ lv_extra.c
│     │  ├─ lv_extra.h
│     │  ├─ lv_extra.mk
│     │  ├─ others
│     │  │  ├─ fragment
│     │  │  │  ├─ lv_fragment.c
│     │  │  │  ├─ lv_fragment.h
│     │  │  │  ├─ lv_fragment_manager.c
│     │  │  │  └─ README.md
│     │  │  ├─ gridnav
│     │  │  │  ├─ lv_gridnav.c
│     │  │  │  └─ lv_gridnav.h
│     │  │  ├─ ime
│     │  │  │  ├─ lv_ime_pinyin.c
│     │  │  │  └─ lv_ime_pinyin.h
│     │  │  ├─ imgfont
│     │  │  │  ├─ lv_imgfont.c
│     │  │  │  └─ lv_imgfont.h
│     │  │  ├─ lv_others.h
│     │  │  ├─ monkey
│     │  │  │  ├─ lv_monkey.c
│     │  │  │  └─ lv_monkey.h
│     │  │  ├─ msg
│     │  │  │  ├─ lv_msg.c
│     │  │  │  └─ lv_msg.h
│     │  │  └─ snapshot
│     │  │     ├─ lv_snapshot.c
│     │  │     └─ lv_snapshot.h
│     │  ├─ README.md
│     │  ├─ themes
│     │  │  ├─ basic
│     │  │  │  ├─ lv_theme_basic.c
│     │  │  │  └─ lv_theme_basic.h
│     │  │  ├─ default
│     │  │  │  ├─ lv_theme_default.c
│     │  │  │  └─ lv_theme_default.h
│     │  │  ├─ lv_themes.h
│     │  │  └─ mono
│     │  │     ├─ lv_theme_mono.c
│     │  │     └─ lv_theme_mono.h
│     │  └─ widgets
│     │     ├─ animimg
│     │     │  ├─ lv_animimg.c
│     │     │  └─ lv_animimg.h
│     │     ├─ calendar
│     │     │  ├─ lv_calendar.c
│     │     │  ├─ lv_calendar.h
│     │     │  ├─ lv_calendar_header_arrow.c
│     │     │  ├─ lv_calendar_header_arrow.h
│     │     │  ├─ lv_calendar_header_dropdown.c
│     │     │  └─ lv_calendar_header_dropdown.h
│     │     ├─ chart
│     │     │  ├─ lv_chart.c
│     │     │  └─ lv_chart.h
│     │     ├─ colorwheel
│     │     │  ├─ lv_colorwheel.c
│     │     │  └─ lv_colorwheel.h
│     │     ├─ imgbtn
│     │     │  ├─ lv_imgbtn.c
│     │     │  └─ lv_imgbtn.h
│     │     ├─ keyboard
│     │     │  ├─ lv_keyboard.c
│     │     │  └─ lv_keyboard.h
│     │     ├─ led
│     │     │  ├─ lv_led.c
│     │     │  └─ lv_led.h
│     │     ├─ list
│     │     │  ├─ lv_list.c
│     │     │  └─ lv_list.h
│     │     ├─ lv_widgets.h
│     │     ├─ menu
│     │     │  ├─ lv_menu.c
│     │     │  └─ lv_menu.h
│     │     ├─ meter
│     │     │  ├─ lv_meter.c
│     │     │  └─ lv_meter.h
│     │     ├─ msgbox
│     │     │  ├─ lv_msgbox.c
│     │     │  └─ lv_msgbox.h
│     │     ├─ span
│     │     │  ├─ lv_span.c
│     │     │  └─ lv_span.h
│     │     ├─ spinbox
│     │     │  ├─ lv_spinbox.c
│     │     │  └─ lv_spinbox.h
│     │     ├─ spinner
│     │     │  ├─ lv_spinner.c
│     │     │  └─ lv_spinner.h
│     │     ├─ tabview
│     │     │  ├─ lv_tabview.c
│     │     │  └─ lv_tabview.h
│     │     ├─ tileview
│     │     │  ├─ lv_tileview.c
│     │     │  └─ lv_tileview.h
│     │     └─ win
│     │        ├─ lv_win.c
│     │        └─ lv_win.h
│     ├─ font
│     │  ├─ korean.ttf
│     │  ├─ lv_font.c
│     │  ├─ lv_font.h
│     │  ├─ lv_font.mk
│     │  ├─ lv_font_dejavu_16_persian_hebrew.c
│     │  ├─ lv_font_fmt_txt.c
│     │  ├─ lv_font_fmt_txt.h
│     │  ├─ lv_font_loader.c
│     │  ├─ lv_font_loader.h
│     │  ├─ lv_font_montserrat_10.c
│     │  ├─ lv_font_montserrat_12.c
│     │  ├─ lv_font_montserrat_12_subpx.c
│     │  ├─ lv_font_montserrat_14.c
│     │  ├─ lv_font_montserrat_16.c
│     │  ├─ lv_font_montserrat_18.c
│     │  ├─ lv_font_montserrat_20.c
│     │  ├─ lv_font_montserrat_22.c
│     │  ├─ lv_font_montserrat_24.c
│     │  ├─ lv_font_montserrat_26.c
│     │  ├─ lv_font_montserrat_28.c
│     │  ├─ lv_font_montserrat_28_compressed.c
│     │  ├─ lv_font_montserrat_30.c
│     │  ├─ lv_font_montserrat_32.c
│     │  ├─ lv_font_montserrat_34.c
│     │  ├─ lv_font_montserrat_36.c
│     │  ├─ lv_font_montserrat_38.c
│     │  ├─ lv_font_montserrat_40.c
│     │  ├─ lv_font_montserrat_42.c
│     │  ├─ lv_font_montserrat_44.c
│     │  ├─ lv_font_montserrat_46.c
│     │  ├─ lv_font_montserrat_48.c
│     │  ├─ lv_font_montserrat_8.c
│     │  ├─ lv_font_simsun_16_cjk.c
│     │  ├─ lv_font_unscii_16.c
│     │  ├─ lv_font_unscii_8.c
│     │  └─ lv_symbol_def.h
│     ├─ hal
│     │  ├─ lv_hal.h
│     │  ├─ lv_hal.mk
│     │  ├─ lv_hal_disp.c
│     │  ├─ lv_hal_disp.h
│     │  ├─ lv_hal_indev.c
│     │  ├─ lv_hal_indev.h
│     │  ├─ lv_hal_tick.c
│     │  └─ lv_hal_tick.h
│     ├─ lvgl.h
│     ├─ lv_api_map.h
│     ├─ lv_conf_internal.h
│     ├─ lv_conf_kconfig.h
│     ├─ misc
│     │  ├─ lv_anim.c
│     │  ├─ lv_anim.h
│     │  ├─ lv_anim_timeline.c
│     │  ├─ lv_anim_timeline.h
│     │  ├─ lv_area.c
│     │  ├─ lv_area.h
│     │  ├─ lv_assert.h
│     │  ├─ lv_async.c
│     │  ├─ lv_async.h
│     │  ├─ lv_bidi.c
│     │  ├─ lv_bidi.h
│     │  ├─ lv_color.c
│     │  ├─ lv_color.h
│     │  ├─ lv_fs.c
│     │  ├─ lv_fs.h
│     │  ├─ lv_gc.c
│     │  ├─ lv_gc.h
│     │  ├─ lv_ll.c
│     │  ├─ lv_ll.h
│     │  ├─ lv_log.c
│     │  ├─ lv_log.h
│     │  ├─ lv_lru.c
│     │  ├─ lv_lru.h
│     │  ├─ lv_math.c
│     │  ├─ lv_math.h
│     │  ├─ lv_mem.c
│     │  ├─ lv_mem.h
│     │  ├─ lv_misc.mk
│     │  ├─ lv_printf.c
│     │  ├─ lv_printf.h
│     │  ├─ lv_style.c
│     │  ├─ lv_style.h
│     │  ├─ lv_style_gen.c
│     │  ├─ lv_style_gen.h
│     │  ├─ lv_templ.c
│     │  ├─ lv_templ.h
│     │  ├─ lv_timer.c
│     │  ├─ lv_timer.h
│     │  ├─ lv_tlsf.c
│     │  ├─ lv_tlsf.h
│     │  ├─ lv_txt.c
│     │  ├─ lv_txt.h
│     │  ├─ lv_txt_ap.c
│     │  ├─ lv_txt_ap.h
│     │  ├─ lv_types.h
│     │  ├─ lv_utils.c
│     │  └─ lv_utils.h
│     └─ widgets
│        ├─ lv_arc.c
│        ├─ lv_arc.h
│        ├─ lv_bar.c
│        ├─ lv_bar.h
│        ├─ lv_btn.c
│        ├─ lv_btn.h
│        ├─ lv_btnmatrix.c
│        ├─ lv_btnmatrix.h
│        ├─ lv_canvas.c
│        ├─ lv_canvas.h
│        ├─ lv_checkbox.c
│        ├─ lv_checkbox.h
│        ├─ lv_dropdown.c
│        ├─ lv_dropdown.h
│        ├─ lv_img.c
│        ├─ lv_img.h
│        ├─ lv_label.c
│        ├─ lv_label.h
│        ├─ lv_line.c
│        ├─ lv_line.h
│        ├─ lv_objx_templ.c
│        ├─ lv_objx_templ.h
│        ├─ lv_roller.c
│        ├─ lv_roller.h
│        ├─ lv_slider.c
│        ├─ lv_slider.h
│        ├─ lv_switch.c
│        ├─ lv_switch.h
│        ├─ lv_table.c
│        ├─ lv_table.h
│        ├─ lv_textarea.c
│        ├─ lv_textarea.h
│        └─ lv_widgets.mk
├─ makefile
├─ README.md
├─ src
│  ├─ autons.cpp
│  ├─ images
│  │  └─ brain_banner_344E.c
│  ├─ JAR-Template
│  │  ├─ drive.cpp
│  │  ├─ odom.cpp
│  │  ├─ PID.cpp
│  │  └─ util.cpp
│  ├─ main.cpp
│  ├─ robot-config.cpp
│  ├─ sylib
│  │  ├─ addrled.cpp
│  │  ├─ math.cpp
│  │  ├─ motor.cpp
│  │  ├─ sylib.cpp
│  │  └─ system.cpp
│  └─ v5lvgl.c
├─ tree.md
└─ vex
   ├─ mkenv.mk
   └─ mkrules.mk

```