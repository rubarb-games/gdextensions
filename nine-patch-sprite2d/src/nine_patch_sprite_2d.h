#ifndef GD_NINE_PATCH_SPRITE_2D
#define GD_NINE_PATCH_SPRITE_2D

#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/rendering_server.hpp>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/texture2d.hpp>

using namespace godot;

class NinePatchSprite2D : public Node2D {
    GDCLASS(NinePatchSprite2D, Node2D);

private:
    RenderingServer *renderer = RenderingServer::get_singleton(); // Rendering server

    uint8_t drawing_step;
    /* 
    About drawing_step:
        0: None,
        1: Refresh texture,
        2: Resizing
    */

    Ref<Texture2D> texture; // Texture to be used for the nine-patch-sprite
    bool texture_centered; // Whether the texture is centered or not
    Vector2 texture_offset; // Offset for the texture to be drawn
    Vector2 texture_size; // Size for the texture to be drawn
    bool draw_center; // Whether to draw the central tiles of the texture
    uint8_t mode_x; // Patch mode for x-axis
    uint8_t mode_y; // Patch mode for y-axis
    Vector2i margin_top_left; // Margins for the top-left corner
    Vector2i margin_bottom_right; // Margins for the bottom-right corner
    Rect2 region_rect; // Region of the texture to be used for the nine-patch-sprite
    int hframes; // Horizontal frames
    int vframes; // Vertical frames
    int frame; // Current frame

    uint8_t _processed_drawn_delay; // Whether the nine-patch-sprite has been drawn at least once

    void _fresh_texture(); // Refresh the texture
    void _update_texture(); // Update the texture
    Callable _func_update_texture; // Function to update the texture
    void _frame_changed(); // Update the nine-patch-sprite when the frame changes
    void _clamp_frame(); // Clamp the frame to the valid range
    void _drag(); // Drag the nine-patch-sprite

protected:
    static void _bind_methods();

public:
    NinePatchSprite2D();
    ~NinePatchSprite2D();

    //void _input(const Ref<InputEvent> &p_event) override;
    void _exit_tree() override;
    void _process(double delta) override;
    void _draw() override;

    void set_texture(const Ref<Texture2D> &p_texture);
    Ref<Texture2D> get_texture() const;
    void set_texture_centered(const bool p_texture_centered);
    bool is_texture_centered() const;
    void set_texture_offset(const Vector2 &p_texture_offset);
    Vector2 get_texture_offset() const;
    void set_texture_size(const Vector2 &p_texture_size);
    Vector2 get_texture_size() const;
    void set_draw_center(const bool p_draw_center);
    bool is_draw_center() const;
    void set_x_patch_mode(const uint8_t p_x_patch_mode);
    uint8_t get_x_patch_mode() const;
    void set_y_patch_mode(const uint8_t p_y_patch_mode);
    uint8_t get_y_patch_mode() const;
    void set_margin_top_left(const Vector2i &p_margin_top_left);
    Vector2i get_margin_top_left() const;
    void set_margin_bottom_right(const Vector2i &p_margin_bottom_right);
    Vector2i get_margin_bottom_right() const;
    void set_region_rect(const Rect2 &p_region_rect);
    Rect2 get_region_rect() const;
    void set_hframes(const int p_hframes);
    int get_hframes() const;
    void set_vframes(const int p_vframes);
    int get_vframes() const;
    void set_frame(const int p_frame);
    int get_frame() const;
};

#endif