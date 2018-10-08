import { createWebsocketSendAction } from '../util';

export const motorOff = id => dispatch => dispatch(createWebsocketSendAction('motor_off_' + id));

export const motorLoad = id => dispatch => dispatch(createWebsocketSendAction('motor_on_load_' + id));

export const motorUnload = id => dispatch => dispatch(createWebsocketSendAction('motor_on_unload_' + id));