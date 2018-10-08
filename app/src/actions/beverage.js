import { createWebsocketSendAction } from '../util';

export const brewBeverage = id => dispatch => dispatch(createWebsocketSendAction('brew_' + id));